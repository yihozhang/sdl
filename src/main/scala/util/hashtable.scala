package sdl.util

import scala.collection.mutable.ArrayBuffer
import sdl.ast._
import scala.collection.mutable
import scala.lms.api.Dsl
import sdl.staging._
import sdl.util._

trait HashTableUtil
    extends Dsl
    with AstUtil
    with UncheckedHelper
    with MemoryBase {
  class Tuple(records: RecordBuffer, pos: Rep[Int]) {
    def apply(i: Int): Rep[Any] = records.elems(i)(pos)
    def runtimeEquals(tuple: Seq[Rep[Any]]): Rep[Boolean] = {
      var i: Int = 0
      // make it short-circuit
      val flag = var_new(true)
      while (i < records.schema.length) {
        elementEquals(tuple(i), this(i), records.schema(i)._2)((), {
          flag = false
        })
        // if (records.schema(i)._2 == Type.NUM) {
        //   if (tuple(i).asInstanceOf[Rep[Int]] != this(i).asInstanceOf[Rep[Int]]) {
        //     flag = false
        //   }
        // } else {
        //   if (tuple(i).asInstanceOf[Rep[String]] != this(i).asInstanceOf[Rep[String]]) {
        //     flag = false
        //   }
        // }
        i += 1
      }
      flag
    }
  }
  // I know it really shouldn't be put here but hey...
  def elementEquals(a: Rep[Any], b: Rep[Any], ty: Type)(
      success: => Rep[Unit],
      failure: => Rep[Unit]
  ) = {
    if (ty == Type.NUM) {
      if (a.asInstanceOf[Rep[Int]] == b.asInstanceOf[Rep[Int]]) {
        success
      } else {
        failure
      }
    } else {
      if (a.asInstanceOf[Rep[String]] == b.asInstanceOf[Rep[String]]) {
        success
      } else {
        failure
      }
    }
  }
  abstract class LegoBuffer {
    def apply(x: Rep[Int]): Tuple
    def update(x: Rep[Int], y: Rep[Any]*): Rep[Unit]
    def resize(x: Rep[Int]): Rep[Unit]
    def append(v: Rep[Any]*): Rep[Int]
    def foreach(f: Tuple => Rep[Unit]): Rep[Unit]
    def stopableForeach(f: Tuple => Rep[Boolean]): Rep[Unit]
    def clear(): Rep[Unit]
    def isEmpty: Rep[Boolean]
    def swap(o: LegoBuffer): Rep[Unit]
  }

  class RecordBuffer(cap0: Rep[Int], val schema: Schema) extends LegoBuffer {
    val cap = var_new(cap0)
    val elems = schema map {
      case (k, Type.NUM) =>
        new ColumnBuffer[Int](cap).asInstanceOf[ColumnBuffer[_]]
      case (k, Type.STR) =>
        new ColumnBuffer[String](cap).asInstanceOf[ColumnBuffer[_]]
    }
    val size = var_new(0)
    // def record_new[T : Manifest](fields: Seq[(String, Boolean, Rep[T] => Rep[_])]): Rep[T]
    def swap(o: LegoBuffer) = {
      val oo = o.asInstanceOf[RecordBuffer]
      c_swap(size, oo.size)
      c_swap(cap, oo.cap)
      elems.zip(oo.elems).foreach {
        case (a, b) => a.swap(b)
      }
    }
    def apply(x: Rep[Int]) = new Tuple(this, x)
    def update(x: Rep[Int], y: Rep[Any]*): Rep[Unit] =
      schema.zipWithIndex foreach {
        case ((f, Type.NUM), i) => {
          (elems(i).asInstanceOf[ColumnBuffer[Int]])(x) =
            y(i).asInstanceOf[Rep[Int]] // need to check at generation time
        }
        case ((f, Type.STR), i) => {
          (elems(i).asInstanceOf[ColumnBuffer[String]])(x) =
            y(i).asInstanceOf[Rep[String]]
        }
      }
    def resize(x: Rep[Int]): Rep[Unit] = {
      printf("buffer.resize %d\\n", x)
      elems foreach { _.resize(x) }
    }

    def isEmpty: Rep[Boolean] = {
      // printf("%d\n", size);
      size == 0
    }

    def append(v: Rep[Any]*): Rep[Int] = {
      if (size == cap) {
        cap *= 4;
        resize(cap)
      }
      this.update(size, v: _*)
      val ret = size: Rep[Int]
      size += 1
      ret
    }

    def foreach(f: Tuple => Rep[Unit]) = {
      for (i <- 0 until size) {
        // NOTE: we only know that hash codes match:
        // client needs to check full keys.
        f(this(i))
      }
    }

    def stopableForeach(f: Tuple => Rep[Boolean]): Rep[Unit] = {
      val i = var_new(0)
      val flag = var_new(true)
      while (flag && i < size) {
        // NOTE: we only know that hash codes match:
        // client needs to check full keys.
        flag = f(this(i))
        i += 1
      }
    }

    def clear(): Rep[Unit] = {
      // printf("%d\n", size);
      size = 0
    }

  }

  class ColumnBuffer[T: Typ](cap0: Rep[Int]) {
    val cap = var_new(cap0)
    // val buf = var_new(NewArray[T](cap0))
    val buf = NewArray[T](cap0)
    val size = var_new(0)
    def swap(o: ColumnBuffer[_]) = {
      c_swap(size, o.size)
      c_swap(cap, o.cap)
      c_swapArray(buf, o.buf)
    }
    def apply(x: Rep[Int]) = buf(x)
    def update(x: Rep[Int], y: Rep[T]): Rep[Unit] = {
      buf(x) = y
    }
    def append(v: Rep[T]): Rep[Int] = {
      if (size == cap) {
        cap *= 4
        resize(cap)
      }
      buf(size) = v
      val ret = size: Rep[Int]
      size += 1
      ret
    }
    def resize(x: Rep[Int]): Rep[Unit] = {
      // buf = array_realloc(buf, x)
    }
    def clear(): Rep[Unit] = {
      size = 0
    }
  }

  def LegoBuffer(size: Rep[Int], schema: Schema): LegoBuffer =
    new RecordBuffer(size, schema)

  trait HashVisitor {
    def foreach(f: Tuple => Rep[Unit]): Rep[Unit]
    def stopableForeach(f: Tuple => Rep[Boolean]): Rep[Unit]
  }
  class LegoLinkedHashMap(
      val hashSize: Rep[Int],
      val bucketSize: Rep[Int],
      val schema: Schema,
      val _indices: List[List[Field]]
  ) {
    val indices = (schema.map(_._1)) :: _indices
    val dataSize = hashSize * bucketSize

    val data = LegoBuffer(dataSize, schema)

    // TODO: could be indices.map blah blah
    val indexedBuffers =
      ((0 until indices.length): Range).map { _ =>
        new ColumnBuffer[Int](dataSize)
      }
    val bucketHashs =
      ((0 until indices.length): Range).map(_ => NewArray[Int](hashSize))

    bucketHashs.foreach(bucketHash => {
      for (i <- 0 until hashSize) {
        bucketHash(i) = -1
      }
    })

    val hashMask = hashSize - 1

    // here we should assume hashSize, bucketSize, schema, and indices will
    // be the same across hashmaps
    def swap(o: LegoLinkedHashMap) = {
      if (indices != o.indices) {
        printerr(indices)
        printerr(o.indices)
      }
      if (schema != o.schema) {
        printerr(schema)
        printerr(o.schema)
      }
      data.swap(o.data)
      indexedBuffers.zip(o.indexedBuffers).foreach {
        case (a, b) => a.swap(b)
      }
      bucketHashs.zip(o.bucketHashs).foreach {
        case (a, b) => c_swapArray(a, b)
      }
    }

    def calcHashInt(x: Rep[Int]) = x
    def calcHashString(x: Rep[String]) = {
      string_hash(x, unit[Long](10L)).asInstanceOf[Rep[Int]]
    }

    def contains(tuple: Rep[Any]*): Rep[Boolean] = {
      val flag = var_new(true)
      this(indices(0), tuple: _*).stopableForeach { tup =>
        {
          if (tup.runtimeEquals(tuple)) {
            flag = false
          }
          flag
        }
      }
      !flag
    }

    def isEmpty: Rep[Boolean] = data.isEmpty

    def +=(tuple: Rep[Any]*) = {
      val dataPos = data.append(tuple: _*): Rep[Int]
      for (((index, indexedBuffer), bucketHash) <- indices
             .zip(indexedBuffers)
             .zip(bucketHashs)) {
        val h = var_new(1)
        for (field <- index) {
          val ((_, typ), i) = schema.zipWithIndex.find(_._1._1 == field).get
          if (typ == Type.NUM) {
            h *= calcHashInt(tuple(i).asInstanceOf[Rep[Int]])
          } else {
            h *= calcHashString(tuple(i).asInstanceOf[Rep[String]])
          }
        }
        val bucket = h & hashMask
        var next = bucketHash(bucket): Rep[Int]
        // printf("next:%d\\n", next);
        bucketHash(bucket) = dataPos
        // printf("dataPos:%d\\n", dataPos);
        indexedBuffer(dataPos) = next
        // val x = var_new(bucketHash(bucket))
        // while (x != -1) {
        // printf("%d ", indexedBuffer(x));
        // x = indexedBuffer(x)
        // }
        // printf("\\n");
      }
    }

    def foreach(f: Tuple => Rep[Unit]): Rep[Unit] = {
      data.foreach(f)
    }

    def stopableForeach(f: Tuple => Rep[Boolean]) = {
      data.stopableForeach(f)
    }

    def apply(ind: List[Field], values: Rep[Any]*): HashVisitor = {
      val (_, indPos) = indices.zipWithIndex.find(_._1 == ind).get
      val h = var_new(1)
      for ((field, i) <- ind.zipWithIndex) {
        val (_, typ) = schema.find(_._1 == field).get
        if (typ == Type.NUM) {
          h *= calcHashInt(values(i).asInstanceOf[Rep[Int]])
        } else {
          h *= calcHashString(values(i).asInstanceOf[Rep[String]])
        }
      }
      val bucket = h & hashMask
      new HashVisitor {
        def checkEqual(tup: Tuple): Rep[Boolean] = {
          var flag = true: Rep[Boolean]
          // TODO: make it short-circuit
          var i: Int = 0
          while (i < ind.length) {
            val field = ind(i)
            val ((_, ty), j) = schema.zipWithIndex.find(_._1._1 == field).get
            elementEquals(values(i), tup(j), ty)({}, {
              flag = false
            })
            i += 1
          }
          flag
        }

        def foreach(f: Tuple => Rep[Unit]): Rep[Unit] = {
          val dataPos = var_new(bucketHashs(indPos)(bucket))
          while (dataPos != -1) {
            val bufElem = data(dataPos)
            dataPos = indexedBuffers(indPos)(dataPos)
            // NOTE: we only know that hash codes match:
            // client needs to check full keys.
            if (checkEqual(bufElem)) f(bufElem)
          }
        }

        def stopableForeach(f: Tuple => Rep[Boolean]) = {
          val dataPos = var_new(bucketHashs(indPos)(bucket))
          val flag = var_new(true)
          while (flag && dataPos != -1) {
            val bufElem = data(dataPos)
            dataPos = indexedBuffers(indPos)(dataPos)
            // NOTE: we only know that hash codes match:
            // client needs to check full keys.
            if (checkEqual(bufElem)) flag = f(bufElem)
          }
        }
      }
    }

    def clear(): Rep[Unit] = {
      data.clear()
      indexedBuffers.foreach(_.clear)
      bucketHashs.foreach(bucketHash => {
        for (i <- 0 until hashSize) {
          bucketHash(i) = -1
        }
      })
    }
  }

}

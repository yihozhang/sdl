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
  val p1 = 1009
  val p2 = 233
  // val p1 = 17
  // val p2 = 13
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
    def foreach(f: Rep[Any] => Rep[Unit]) = {
      var i: Int = 0
      while (i < records.schema.length) {
        f(this(i))
        i += 1
      }
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
      // for (i <- 0 until size) {
      //   this(i).foreach(printf("%d ", _))
      //   printf("\\n");
      // }
      ret
    }

    def foreach(f: Tuple => Rep[Unit]) = {
      for (i <- 0 until size) {
        f(this(i))
      }
    }

    def stopableForeach(f: Tuple => Rep[Boolean]): Rep[Unit] = {
      val i = var_new(0)
      val flag = var_new(true)
      while (flag && i < size) {
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
    val buf = var_new(NewArray[T](cap0))
    // val buf = NewArray[T](cap0)
    val size = var_new(0)
    def swap(o: ColumnBuffer[_]) = {
      c_swap(size, o.size)
      c_swap(cap, o.cap)
      // c_swapArray(buf, o.buf)
      c_swap(buf, o.buf)
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
      ((0 until indices.length): Range).map(_ => var_new(NewArray[Int](hashSize)))

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
        case (a, b) => c_swap(a, b)
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
      // printf("INSERT INTO HASHTABLE")
      // tuple.foreach(ele => printf("%d ", ele))
      // printf("\\n")
      var dataPos = data.append(tuple: _*): Rep[Int]
      for (((index, indexedBuffer), bucketHash) <- indices
             .zip(indexedBuffers)
             .zip(bucketHashs)) {
        val h = var_new(0)
        for (field <- index) {
          val ((_, typ), i) = schema.zipWithIndex.find(_._1._1 == field).get
          if (typ == Type.NUM) {
            h = h * p1 + calcHashInt(tuple(i).asInstanceOf[Rep[Int]]) + p2
          } else {
            h = h * p1 + calcHashString(tuple(i).asInstanceOf[Rep[String]]) + p2
          }
        }
        val bucket = h & hashMask

        // printf("%d\\n", bucket);
        var next = bucketHash(bucket): Rep[Int]
        // printf("next:%d\\n", next);
        bucketHash(bucket) = dataPos
        // printf("dataPos:%d\\n", dataPos);
        indexedBuffer(dataPos) = next
        // val x = var_new(bucketHash(bucket))
        // while (x != -1) {
        // printf("%d ", x);
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
      val h = var_new(0)
      for ((field, i) <- ind.zipWithIndex) {
        val (_, typ) = schema.find(_._1 == field).get
        if (typ == Type.NUM) {
          h = h * p1 + calcHashInt(values(i).asInstanceOf[Rep[Int]]) + p2
        } else {
          h = h * p1 + calcHashString(values(i).asInstanceOf[Rep[String]]) + p2
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

          // printf("FOREACH\\n")
          // printf("bucket: %d\\n", bucket);
          // val x = var_new(bucketHashs(indPos)(bucket))
          // while (x != -1) {
          // printf("%d: ", x);
          // data(x).foreach(printf("%d ", _))
          // printf(":")
          // x = indexedBuffers(indPos)(x)
          // }
          // printf("\\n");
          // printf("END FOREACH\\n")
          var dataPos = bucketHashs(indPos)(bucket)
          while (dataPos != -1) {
            // printf("dataPPOS: %d", dataPos)
            val bufElem = data(dataPos)
            if (checkEqual(bufElem)) f(bufElem)
            dataPos = indexedBuffers(indPos)(dataPos)
            // f(bufElem)
          }
        }

        def stopableForeach(f: Tuple => Rep[Boolean]) = {
          // printf("STOPABLE FOREACH\\n")
          // val x = var_new(bucketHashs(indPos)(bucket))
          // while (x != -1) {
          // printf("%d ", x);
          // x = indexedBuffers(indPos)(x)
          // }
          // printf("\\n");
          // printf("END STOPABLE FOREACH\\n")
          var dataPos = bucketHashs(indPos)(bucket): Rep[Int]
          val flag = var_new(true)
          while (flag && dataPos != -1) {
            val bufElem = data(dataPos)
            if (checkEqual(bufElem)) flag = f(bufElem)
            dataPos = indexedBuffers(indPos)(dataPos)
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

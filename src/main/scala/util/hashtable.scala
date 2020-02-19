package sdl.util

import scala.collection.mutable.ArrayBuffer
import sdl.ast._
import scala.collection.mutable
import scala.lms.api.Dsl
import sdl.staging._
import sdl.util._

trait HashTableUtil
    extends Dsl
    with SArrayBase
    with AstUtil
    with TupleBase
    with UncheckedHelper {
  class Tuple(records: RecordBuffer, pos: Rep[Int]) {
    def apply(i: Int): Rep[Any] = records.elems(i)(pos)
  }
  abstract class LegoBuffer {
    def apply(x: Rep[Int]): Tuple
    def update(x: Rep[Int], y: Rep[Any]*): Rep[Unit]
    def resize(x: Rep[Int]): Rep[Unit]
    def append(v: Rep[Any]*): Rep[Int]
    def foreach(f: Tuple => Rep[Unit]): Rep[Unit]
    def clear(): Rep[Unit]
    /*def sort(
        comp: Function2[Rep[T], Rep[T], Rep[Int]],
        len: Rep[Int]
    ): Rep[Unit]*/
  }

  class RecordBuffer(var cap: Rep[Int], schema: Schema) extends LegoBuffer {
    val elems = schema map {
      case (k, Type.NUM) =>
        new ColumnBuffer[Int](cap).asInstanceOf[ColumnBuffer[_]]
      case (k, Type.STR) =>
        new ColumnBuffer[String](cap).asInstanceOf[ColumnBuffer[_]]
    }
    var size = var_new(0)
    // def record_new[T : Manifest](fields: Seq[(String, Boolean, Rep[T] => Rep[_])]): Rep[T]
    def apply(x: Rep[Int]) = new Tuple(this, x)
    def update(x: Rep[Int], y: Rep[Any]*): Rep[Unit] =
      schema.zipWithIndex foreach {
        case ((f, Type.NUM), i) => {
          elems(i).asInstanceOf[ColumnBuffer[Int]](x) =
            y(i).asInstanceOf[Rep[Int]] // need to check at generation time
        }
        case ((f, Type.STR), i) => {
          elems(i).asInstanceOf[ColumnBuffer[String]](x) =
            y(i).asInstanceOf[Rep[String]]
        }
      }
    def resize(x: Rep[Int]): Rep[Unit] = {
      printf("buffer.resize %ld\n", x)
      elems foreach { _.resize(x) }
    }

    def append(v: Rep[Any]*): Rep[Int] = {
      if (size == cap) {
        cap *= 4;
        resize(cap)
      }
      this.update(size, v: _*)
      val ret = size
      size += 1
      ret
    }

    def foreach(f: Tuple => Rep[Unit]) = {
      for (i <- 0 until size) {
        f(this(i))
      }
    }

    def clear(): Rep[Unit] = {
        size = 0
    }

  }

  class ColumnBuffer[T: Typ](cap0: Rep[Int]) {
    // val buf = var_new(NewArray[T](size))
    implicit def arrayType: Typ[Array[T]] = typ
    val cap = var_new(cap0)
    val buf = var_new(NewArray[T](cap0))
    var size = 0: Rep[Int]
    def apply(x: Rep[Int]) = buf(x)
    def update(x: Rep[Int], y: Rep[T]): Rep[Unit] = buf(x) = y
    def append(v: Rep[T]): Rep[Int] = {
      if (size == cap) {
        cap *= 4
        resize(cap)
      }
      buf(size) = v
      val ret = size
      size += 1
      ret
    }
    def resize(x: Rep[Int]): Rep[Unit] = {
      buf = array_realloc(buf, x)
    }
    def clear(): Rep[Unit] = {
        size = 0
    }
  }

  def LegoBuffer(size: Rep[Int], schema: Schema): LegoBuffer =
    new RecordBuffer(size, schema)

  trait HashVisitor {
    def foreach(f: Tuple => Rep[Unit]): Rep[Unit]
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
    // val indexedBuffers = new Array[ColumnBuffer[Int]](indices.length)
    // for (i <- 0 to indices.length) {
    //     indexedBuffers(i) = new ColumnBuffer[Int](dataSize)
    // }
    val indexedBuffers =
      ((0 until indices.length): Range).map { _ =>
        new ColumnBuffer[Int](dataSize)
      }
    val bucketHashs =
      ((0 until indices.length): Range).map(_ => NewArray[Int](hashSize))
    // val bucketHashs = new Array[Rep[Array[Int]]](indices.length + 1)
    // for (i <- 0 to indices.length) {
    //     bucketHashs(i) = NewArray[Int](hashSize)
    //     for (j <- 0 until hashSize) {
    //        bucketHashs(i)(j) = -1
    //     }
    // }

    val hashMask = hashSize - 1

    def calcHashInt(x: Rep[Int]) = x
    def calcHashString(x: Rep[String]) = {
      string_hash(x, unit[Long](10L)).asInstanceOf[Rep[Int]]
    }

    def +=(tuple: Rep[Any]*) = {
      val dataPos = data.append(tuple: _*)
      for (((index, indexedBuffer), bucketHash) <- indices
             .zip(indexedBuffers)
             .zip(bucketHashs)) {
        var h = 1: Rep[Int]
        for (field <- index) {
          val ((_, typ), i) = schema.zipWithIndex.find(_._1._1 == field).get
          if (typ == Type.NUM) {
            h *= calcHashInt(tuple(i).asInstanceOf[Rep[Int]])
          } else {
            h *= calcHashString(tuple(i).asInstanceOf[Rep[String]])
          }
        }
        val bucket = h & hashMask
        val next = bucketHash(bucket)
        bucketHash(bucket) = dataPos
        indexedBuffer(dataPos) = next
      }
    }
    def foreach(f: Tuple => Rep[Unit]): Rep[Unit] = {
      data.foreach(f)
    }

    def apply(ind: List[Field], values: Rep[Any]*) = {
      val (_, indPos) = indices.zipWithIndex.find(_._1 == ind).get
      var h = 1: Rep[Int]
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

        def foreach(f: Tuple => Rep[Unit]): Rep[Unit] = {

          var dataPos = bucketHashs(indPos)(bucket)
          while (dataPos != -1) {
            val bufElem = data(dataPos)
            dataPos = indexedBuffers(indPos)(dataPos)
            // NOTE: we only know that hash codes match:
            // client needs to check full keys.
            f(bufElem)
          }
        }
        /*
      def indexWhere(f: Rep[A] => Rep[Boolean]): Rep[Int] = {
        val h: Rep[Int] = calcHashCode(k)
        val bucket = h & hashMask

        var dataPos = bucketHash(bucket)
        var done = dataPos == -1
        while (!done) {
          val bufElem = data(dataPos)
          // NOTE: we only know that hash codes match:
          // client needs to check full keys.
          if (f(bufElem)) {
            done = true
          } else {
            dataPos = bucketNext(dataPos)
            done = dataPos == -1
          }
        }
        dataPos
      }*/
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

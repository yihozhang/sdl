package sdl.util

import scala.collection.mutable.ArrayBuffer
import sdl.ast._
import scala.collection.mutable
import scala.lms.api.Dsl
import sdl.staging._
import sdl.util._

trait TableUtil
    extends Dsl
    with AstUtil
    with ScannerLowerBase
    with UncheckedHelper
    with HashTableUtil
    with MemoryBase {

  object DefaultSize {
    val hashSize = 1 << 24
    val bucketSize = 1
  }

  object SmallTableSize {
    val hashSize = 1 << 10
    val bucketSize = 1 << 10
    // val hashSize = 1 << 22
    // val bucketSize = 1
  }

  case class Table(val decl: Decl, val indices: List[List[Field]]) {
    val rel = decl.rel
    val schema = decl.schema
    val tupleSize = schema.length
    val hashSize =
      if (rel.startsWith("@")) SmallTableSize.hashSize
      else DefaultSize.hashSize
    val bucketSize =
      if (rel.startsWith("@")) SmallTableSize.bucketSize
      else DefaultSize.bucketSize
    var tab: LegoLinkedHashMap =
      new LegoLinkedHashMap(hashSize, bucketSize, schema, indices)

    def contains(tuple: Rep[Any]*) = {
      tab.contains(tuple: _*)
    }
    def push(tuple: Rep[Any]*) = {
      if (!tab.contains(tuple: _*)) {
        tab += (tuple: _*)
      }
    }

    def clear() = {
      tab.clear()
    }

    def foreach(f: Tuple => Rep[Unit]) = {
      tab.foreach(f)
    }

    def stopableForeach(f: Tuple => Rep[Boolean]) {
      tab.stopableForeach(f)
    }

    def isEmpty: Rep[Boolean] = tab.isEmpty

    def apply(ind: List[Field], values: Rep[Any]*) = tab.apply(ind, values: _*)

    def loadFrom(filename: String) = {
      val s = new Scanner(filename)
      while (s.hasNext) {
        val last = schema.last
        val tuple = schema.map { field =>
          val str = s.next(if (field == last) '\n' else '\t')
          if (field._2 == Type.NUM) {
            atoi(str).asInstanceOf[Rep[Any]]
          } else {
            str.asInstanceOf[Rep[Any]]
          }
        }
        tab += (tuple: _*)
      }
    }

    def storeTo(filename: String) = {
      val p = new Printer(filename)
      tab.foreach { tuple =>
        for (((field, ty), i) <- schema.zipWithIndex) {
          if (ty == Type.NUM) {
            p.printf("%d", tuple(i))
          } else {
            p.printll(tuple(i).asInstanceOf[Rep[String]])
          }
          p.prints((if (i == tupleSize - 1) "\\n" else "\\t"))
        }
      }
      p.close
    }
  }

  object Table {
    def swap(a: Table, b: Table) {
      a.tab.swap(b.tab)
    }
  }

  class Printer(filename: String) {
    val file = c_fopen(filename, "w")
    def printf(mod: Rep[String], v: Rep[Any]) = c_fprintf(file, mod, v)
    def prints(s: String) = c_prints(file, unit(s))
    // only used to print read-in string
    def printll(s: Rep[String]) = c_printll(file, s)
    def close = c_fclose(file)
  }

  class Scanner(name: Rep[String]) {
    val fd = open(name)
    val fl = filelen(fd)
    val data = mmap[Char](fd, fl)
    var pos = 0: Rep[Int]

    def next(d: Rep[Char]) = {
      val start = pos: Rep[Int] // force read
      while (data(pos) != d) pos += 1
      val len = pos - start
      pos += 1
      stringFromCharArray(data, start, len)
    }

    def nextInt(d: Rep[Char]) = {
      val start = pos: Rep[Int] // force read
      var num = 0
      while (data(pos) != d) {
        num = num * 10 + (data(pos) - '0').toInt
        pos += 1
      }
      pos += 1
      num
    }

    def hasNext = pos < fl
    def done = close(fd)
  }

  class TableManager(env: Map[RelId, Decl], indices: List[IndexSchema]) {
    val tables = new Array[Table](env.size)

    val relIdToTabId = mutable.Map[RelId, Int]()

    for (((tabName, decl), i) <- env.toList.zipWithIndex) {
      tables(i) =
        new Table(decl, indices.filter(_.rel == tabName).map(_.fields))
      relIdToTabId(tabName) = i
    }

    def apply(relId: RelId): Table = tables(relIdToTabId(relId))
  }

}

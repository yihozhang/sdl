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
    with SArrayBase
    with TupleBase
    with ElementBase
    with ScannerBase
    with UncheckedHelper
    with HashTableUtil {
  object Defaults {
    val hashSize = 1 << 17
    val bucketSize = 1 << 3
  }
  case class Table(schema: Schema, indices: List[List[Field]]) {
    import Defaults._
    val tupleSize = schema.length
    val tab = new LegoLinkedHashMap(hashSize, bucketSize, schema, indices)
    def push(tuple: Rep[Any]*) {
      tab += (tuple: _*)
    }

    def clear() {
      tab.clear()
    }

    def foreach(f: Tuple => Rep[Unit]) = {
      tab.foreach(f)
    }

    def isEmpty: Rep[Boolean] = ???

    def loadFrom(filename: String) {
      val s = newScanner(filename)
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
    def storeTo(filename: String) {
      val p = new Printer(filename)
      tab.foreach { tuple =>
        for (((field, ty), i) <- schema.zipWithIndex) {
          val modifier = (if (ty == Type.NUM) "%d" else "%s") +
            (if (i == tupleSize - 1) "\n" else "\t")
          p.printf(modifier, tuple(i))
        }
      }
      p.close
    }

    def stopableForeach(f: Tuple => Rep[Boolean]) {
      ???
    }
    /*
    def print() {
      for (field <- schema) {
        printf("%s\t", field._1)
      }
      printf("\n")
      for (i <- 0 until length) {
        for (j <- 0 until tupleSize) {
          if (schema(j)._2 == Type.NUM) {
            printf("%d\t", tab(i * tupleSize + j))
          } else {
            printf("%s\t", tab(i * tupleSize + j))
          }
        }
        println()
      }
    }
   */
  }

  object Table {
    def swap(a: Table, b: Table) {
      // val tmpTab = a.tab
      // a.tab = b.tab
      // b.tab = tmpTab
    }
  }
  class Printer(filename: String) {
    val file = c_fopen(filename, "w")
    def printf(mod: Rep[String], v: Rep[Any]) = c_fprintf(file, mod, v)
    def close = fclose(file)
  }

  class TableManager(env: Map[RelId, Decl], indices: List[IndexSchema]) {
    val tables = new Array[Table](env.size)

    val relIdToTabId = mutable.Map[RelId, Int]()

    for (((tabName, decl), i) <- env.toList.zipWithIndex) {
      tables(i) =
        new Table(decl.schema, indices.filter(_.rel == tabName).map(_.fields))
      relIdToTabId(tabName) = i
    }

    def apply(relId: RelId): Table = tables(relIdToTabId(relId))
  }

}

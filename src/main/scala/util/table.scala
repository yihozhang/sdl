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
    with PrinterBase {
  case class Table(schema: Schema) {
    val tupleSize = schema.length
    var tab: Rep[SArray] = newSArray()
    var length = 0: Rep[Int]
    def get(i: Rep[Int]) = newTuple(tab, i * tupleSize, tupleSize)
    def push(tuple: Rep[Element]*) {
      tuple.foreach(tab.push(_))
      length += 1
    }
    def loadFrom(filename: String) {
      val s = newScanner(filename)
      while (s.hasNext) {
        val last = schema.last
        schema.map { field =>
          tab.push {
            Table.toElement(s.next(if (field == last) '\n' else '\t'), field._2)
          }
        }
        length += 1
      }
    }
    def clear() {
      length = 0
      tab.clear()
    }
    def storeTo(filename: String) {
      val p = newPrinter(filename)
      for (i <- 0 until length) {
        for (j <- 0 until tupleSize) {
          p.write(tab(i * tupleSize + j).toString())
          if (j != tupleSize - 1) {
            p.write("\t")
          } else {
            p.write("\n")
          }
        }
      }
      p.close
    }

    def foreach(f: Rep[Tuple] => Unit) {
      for (i <- 0 until length) {
        f(get(i))
      }
    }

    def stopableForeach(f: Rep[Tuple] => Rep[Boolean]) {
      var i = 0
      var flag = true
      while (flag && i < length) {
        if (!f(get(i))) {
          flag = false
        }
        i += 1
      }
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
    private def toElement(s: Rep[String], ty: Type): Rep[Element] = {
      if (ty == Type.NUM) {
        newIntElement(s.toInt)
      } else {
        newStringElement(s)
      }
    }
    
    def swap(a: Table, b: Table) {
      val tmpTab = a.tab
      a.tab = b.tab
      b.tab = tmpTab
      val tmpLen = a.length
      a.length = b.length
      b.length = tmpLen
    }

  }

  class TableManager(env: Map[RelId, Decl]) {
    val tables = new Array[Table](env.size)

    val relIdToTabId = mutable.Map[RelId, Int]()

    for (((tabName, decl), i) <- env.toList.zipWithIndex) {
      tables(i) = new Table(decl.schema)
      relIdToTabId(tabName) = i
    }

    def apply(relId: RelId): Table = tables(relIdToTabId(relId))
  }

}

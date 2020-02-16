package sdl.util

import scala.collection.mutable.ArrayBuffer
import sdl.ast._
import scala.collection.mutable

import sdl.staging.Scanner
import sdl.staging.Printer

trait SArray[T] {
  def push(v: T): SArray[T]
  def apply(i: Int): T
  // def last: T
  def free(): Unit
  def clear(): Unit
}
object SArray {
  def apply[T](): SArray[T] = new SArrayBuffer[T]
}

class SArrayBuffer[T] extends SArray[T] {
  val arr = new ArrayBuffer[T]

  override def push(v: T): SArray[T] = {
    arr += v
    this
  }

  override def apply(i: Int): T = arr(i)
  // override def last: T = arr.last

  override def free(): Unit = ()
  override def clear(): Unit = {
    arr.clear()
  }

}

case class Table(schema: Schema) {
  val tupleSize = schema.length
  var tab = SArray[Element]
  var length = 0
  def push(tuple: Array[Element]) {
    for (i <- 0 until tupleSize) {
      tab.push(tuple(i))
    }
  }
  def loadFrom(filename: String) {
    val s = new Scanner(filename)
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
    val p = new Printer(filename)
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
}

object Table {
  private def toElement(s: String, ty: Type): Element = {
    if (ty == Type.NUM) {
      IntElement(s.toInt)
    } else {
      StringElement(s)
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

package sdl.util
import sdl.ast._
import scala.collection.mutable.ArrayBuffer

class SArray {
  // val arr = new ArrayBuffer[T]
  val arr = new ArrayBuffer[Element]

  def push(v: Element): SArray = {
    arr += v
    this
  }

  def apply(i: Int): Element = arr(i)
  // override def last: T = arr.last

  def free(): Unit = ()
  def clear(): Unit = {
    arr.clear()
  }

}

package sdl.util

sealed abstract class Element
case class IntElement(value: Int) extends Element {
  override def toString: String = value.toString()
}
case class StringElement(value: String) extends Element {
  override def toString: String = value
}

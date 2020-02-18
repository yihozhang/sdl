package sdl.staging

import sdl.util.Element
import scala.lms.common._
import scala.reflect.SourceContext
import scala.lms.api.Dsl


trait ElementBase extends Base { this: Dsl =>
  implicit def elementTyp: Typ[Element]
  implicit class RepElementOps(s: Rep[Element]) {
  }
  def newIntElement(v: Rep[Int]): Rep[Element]
  def newStringElement(v: Rep[String]): Rep[Element]
}

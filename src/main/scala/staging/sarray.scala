package sdl.staging

import sdl.util._
import scala.lms.common._
import scala.reflect.SourceContext
import scala.lms.api.Dsl

trait SArrayBase extends Base { this: Dsl =>
  implicit def arrayTyp: Typ[SArray]
  implicit class RepSArrayOps(s: Rep[SArray]) {
    def push(e: Rep[Element]) = sArrayPush(s, e)
    def apply(i: Rep[Int]) = sArrayApply(s, i)
    def free(): Rep[Unit] = sArrayFree(s)
    def clear(): Rep[Unit] = sArrayClear(s)
  }
  def newSArray()(
      implicit pos: SourceContext
  ): Rep[SArray]
  def sArrayApply(s: Rep[SArray], i: Rep[Int])(
      implicit pos: SourceContext
  ): Rep[Element]
  def sArrayPush(s: Rep[SArray], e: Rep[Element])(
      implicit pos: SourceContext
  ): Rep[Unit]
  def sArrayFree(s: Rep[SArray])(
      implicit pos: SourceContext
  ): Rep[Unit]
  def sArrayClear(s: Rep[SArray])(
      implicit pos: SourceContext
  ): Rep[Unit]
}

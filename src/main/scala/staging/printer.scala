package sdl.staging

import scala.lms.common._
import scala.lms.api._
import scala.reflect.SourceContext
import sdl.util.Printer

trait PrinterBase extends Base { this: Dsl =>
  implicit def printerTyp: Typ[Printer]
  implicit class RepPrinterOps(s: Rep[Printer]) {
    def write(str: Rep[String])(implicit pos: SourceContext) =
      printerWrite(s, str)
    def close(implicit pos: SourceContext) = printerClose(s)
  }
  def newPrinter(fn: Rep[String])(implicit pos: SourceContext): Rep[Printer]
  def printerWrite(s: Rep[Printer], str: Rep[String])(
      implicit pos: SourceContext
  )
  def printerClose(s: Rep[Printer])(implicit pos: SourceContext): Rep[Unit]
}

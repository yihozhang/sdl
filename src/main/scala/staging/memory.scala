package sdl.staging

import scala.lms.common._
import scala.lms.api._
import scala.reflect.SourceContext
import java.io.File

trait MemoryBase extends Base { this: Dsl =>
  implicit def fileTyp: Typ[File]
  def c_fopen(filename: Rep[String], mode: Rep[String])(
      implicit pos: SourceContext
  ): Rep[File]

  def c_fprintf(file: Rep[File], mod: Rep[String], value: Rep[Any])(
      implicit pos: SourceContext
  )
  def c_fclose(file: Rep[File])(implicit pos: SourceContext): Rep[Unit]
  def c_prints(f: Rep[File], s: Rep[String]): Rep[Int]
  def c_printll(f: Rep[File], s: Rep[String]): Rep[Int]

}

trait MemoryExp extends MemoryBase with UncheckedOps { this: DslExp =>
  implicit def fileTyp: Typ[File] = manifestTyp

  def c_fopen(filename: Rep[String], mode: Rep[String])(
      implicit pos: SourceContext
  ): Rep[File] = uncheckedPure[File]("fopen(", filename, ",", mode, ")")

  def c_fprintf(file: Rep[File], mod: Rep[String], value: Rep[Any])(
      implicit pos: SourceContext
  ) = unchecked[Int]("fprintf(", file, ",", mod, ",", value, ")")
  def c_fclose(file: Rep[File])(implicit pos: SourceContext): Rep[Unit] =
    unchecked[Unit]("fclose(", file, ")")
  def c_prints(f: Rep[File], s: Rep[String]): Rep[Int] = unchecked[Int]("fprintf(", f, ",", s, ")")
  def c_printll(f: Rep[File], s: Rep[String]): Rep[Int] = unchecked[Int]("printll(",f,",",s,")")
}

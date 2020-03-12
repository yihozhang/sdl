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
  def c_swap(a: Var[Any], b: Var[Any]): Rep[Unit]
  def c_swapArray(a: Rep[Any], b: Rep[Any]): Rep[Unit]
  // def c_swapInt(a: Rep[Int], b: Rep[Int]): Rep[Unit]
}

trait MemoryExp extends MemoryBase with UncheckedOpsExp { this: DslExp =>
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
  def c_swapArray(a: Rep[Any], b: Rep[Any]): Rep[Unit] = unchecked[Unit]("SWAP(",a,",",b,")")
  def c_swap(a: Var[Any], b: Var[Any]): Rep[Unit] = reflectMutable[Unit](CSwap(a,b))
  case class CSwap(a: Var[Any], b: Var[Any]) extends Def[Unit]
  // def c_swapInt(a: Rep[Int], b: Rep[Int]): Rep[Unit] = c_swap(a, b)
}

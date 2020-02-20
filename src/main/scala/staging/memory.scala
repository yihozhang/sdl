package sdl.staging

import scala.lms.common._
import scala.lms.api._
import scala.reflect.SourceContext
import java.io.File

trait MemoryBase extends Base { this: Dsl =>
  implicit def fileTyp: Typ[File]
  def c_fopen(filename: Rep[String], mode: String)(
      implicit pos: SourceContext
  ): Rep[File]

  def c_fprintf(file: Rep[File], mod: Rep[String], value: Rep[Any])(
      implicit pos: SourceContext
  )
  def c_fclose(file: Rep[File])(implicit pos: SourceContext): Rep[Unit]

  // rawSrc"fopen($filename,mode)".as[File]
}

trait MemoryExp extends MemoryBase with UncheckedOps { this: DslExp =>
  implicit def fileTyp: Typ[File]
//   case class FOpen(filename: Exp[String], mode: String) extends Def[File]
//   case class FPrintf(file: Exp[File], mod: Exp[String], value: Exp[Any])
//       extends Def[Unit]
//   case class FClose(file: Exp[File]) extends Def[Unit]

//   override def c_fopen(filename: Rep[String], mode: String)(
//       implicit pos: SourceContext
//   ): Rep[File] = FOpen(filename, mode)

//   override def c_fprintf(file: Rep[File], mod: Rep[String], value: Rep[Any])(
//       implicit pos: SourceContext
//   ) = FPrintf(file, mod, value)
//   override def c_fclose(file: Rep[File])(implicit pos: SourceContext): Rep[Unit] =
//     FClose(file)

//   override def mirror[A:Typ](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = (e match {
//     case Reflect(FOpen(file, m), u, es) => reflectMirrored(Reflect(FOpen(f(file), m), mapOver(f,u), f(es)))(mtype(typ[A]), pos)
//     case Reflect(FPrintf(file,m,v), u, es) => reflectMirrored(Reflect(FPrintf(f(file), f(m), f(v)), mapOver(f,u), f(es)))(mtype(typ[A]), pos)
//     case Reflect(FClose(file), u, es) => reflectMirrored(Reflect(FClose(f(file)), mapOver(f,u), f(es)))(mtype(typ[A]), pos)
//     case _ => super.mirror(e,f)
//   }).asInstanceOf[Exp[A]]

  def c_fopen(filename: Rep[String], mode: String)(
      implicit pos: SourceContext
  ): Rep[File] = uncheckedPure[File]("fopen(", filename, ",", mode, ")")

  def c_fprintf(file: Rep[File], mod: Rep[String], value: Rep[Any])(
      implicit pos: SourceContext
  ) = unchecked[Int]("fprintf(", file, ",", mod, ",", value, ")")
  def c_fclose(file: Rep[File])(implicit pos: SourceContext): Rep[Unit] =
    unchecked[Unit]("fclose(", file, ")")

}

package sdl.staging

import sdl.util._
import scala.lms.common._
import scala.reflect.SourceContext
import scala.lms.api.Dsl
import sdl.ast.AstUtil

trait TupleBase extends Base with AstUtil { this: Dsl =>
  implicit def tupleTyp: Typ[Tuple]
  implicit class RepTupleOps(s: Rep[Tuple]) {
    def apply(i: Rep[Int])(implicit pos: SourceContext) = tupleApply(s, i)
  }
  def newTuple(arr: Rep[SArray], offset: Rep[Int], schema: Schema)(
      implicit pos: SourceContext
  ): Rep[Tuple]
  def tupleApply(s: Rep[Tuple], i: Rep[Int])(
      implicit pos: SourceContext
  ): Rep[Element]
}
/*
trait TupleExp extends ScannerBase with EffectExp { this: DslExp =>
  implicit def tupleTyp: Typ[Scanner] = manifestTyp

  case class TupleApply(s: Rep[Tuple], i: Rep[Int]) extends Def[Element]
  case class TupleNew(s: Rep[Tuple], i: Rep[Int]) extends Def[Tuple]

  override def newTuple(
      arr: Rep[SArray],
      offset: Rep[Int],
      tupleSize: Rep[Int]
  )(implicit pos: SourceContext): Rep[Tuple] =
    reflectMutable(TupleNew(fn))

  override def tupleApply(
      s: Rep[Tuple],
      i: Rep[Int]
  )(implicit pos: SourceContext): Rep[Tuple] =
    TupleApply(s, i)
}

trait ScalaGenScanner extends ScalaGenEffect {
  val IR: ScannerExp
  import IR._

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case ScannerNew(fn) =>
      emitValDef(sym, src"new scala.lms.tutorial.Scanner($fn)")
    case ScannerNext(s, d) => emitValDef(sym, src"$s.next($d)")
    case ScannerHasNext(s) => emitValDef(sym, src"$s.hasNext")
    case ScannerClose(s)   => emitValDef(sym, src"$s.close")
    case _                 => super.emitNode(sym, rhs)
  }
}

trait ScannerLowerBase extends Base with UncheckedOps { this: Dsl =>
  def open(name: Rep[String]): Rep[Int]
  def close(fd: Rep[Int]): Rep[Unit]
  def filelen(fd: Rep[Int]): Rep[Int]
  def mmap[T: Typ](fd: Rep[Int], len: Rep[Int]): Rep[Array[T]]
  def stringFromCharArray(
      buf: Rep[Array[Char]],
      pos: Rep[Int],
      len: Rep[Int]
  ): Rep[String]
  def prints(s: Rep[String]): Rep[Int]
  def infix_toInt(c: Rep[Char]): Rep[Int] = c.asInstanceOf[Rep[Int]]
}

trait ScannerLowerExp extends ScannerLowerBase with UncheckedOpsExp {
  this: DslExp =>
  def open(name: Rep[String]) = uncheckedPure[Int]("open(", name, ",0)")
  def close(fd: Rep[Int]) = unchecked[Unit]("close(", fd, ")")
  def filelen(fd: Rep[Int]) =
    uncheckedPure[Int]("fsize(", fd, ")") // FIXME: fresh name
  def mmap[T: Typ](fd: Rep[Int], len: Rep[Int]) =
    uncheckedPure[Array[T]](
      "mmap(0, ",
      len,
      ", PROT_READ, MAP_FILE | MAP_SHARED, ",
      fd,
      ", 0)"
    )
  def stringFromCharArray(
      data: Rep[Array[Char]],
      pos: Rep[Int],
      len: Rep[Int]
  ): Rep[String] = uncheckedPure[String](data, "+", pos)
  def prints(s: Rep[String]): Rep[Int] = unchecked[Int]("printll(", s, ")")
}

trait CGenScannerLower extends CGenUncheckedOps
*/

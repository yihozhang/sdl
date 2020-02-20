package scala.lms.api

import scala.lms.common._
import scala.reflect.SourceContext

trait ScalaGenUtilOps extends ScalaGenBase {
  val IR: UtilOpsExp
  import IR._

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case ObjHashCode(o) => emitValDef(sym, src"$o.##")
    case _              => super.emitNode(sym, rhs)
  }
}

trait DslGen
    extends ScalaGenNumericOps
    with ScalaGenPrimitiveOps
    with ScalaGenBooleanOps
    with ScalaGenIfThenElse
    with ScalaGenEqual
    with ScalaGenRangeOps
    with ScalaGenOrderingOps
    with ScalaGenMiscOps
    with ScalaGenArrayOps
    with ScalaGenStringOps
    with ScalaGenSeqOps
    with ScalaGenFunctions
    with ScalaGenWhile
    with ScalaGenStaticData
    with ScalaGenVariables
    with ScalaGenObjectOps
    with ScalaGenUtilOps {
  val IR: DslExp

  import IR._

  override def quote(x: Exp[Any]) = x match {
    case Const('\n') if x.tp == typ[Char] => "'\\n'"
    case Const('\t') if x.tp == typ[Char] => "'\\t'"
    case Const(0) if x.tp == typ[Char]    => "'\\0'"
    case _                                => super.quote(x)
  }
  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case IfThenElse(c, Block(Const(true)), Block(Const(false))) =>
      emitValDef(sym, quote(c))
    case PrintF(f: String, xs) =>
      emitValDef(sym, src"printf(${Const(f) :: xs})")
    case GenerateComment(s) =>
      stream.println("// " + s)
    case Comment(s, verbose, b) =>
      stream.println("val " + quote(sym) + " = {")
      stream.println("//#" + s)
      if (verbose) {
        stream.println("// generated code for " + s.replace('_', ' '))
      } else {
        stream.println("// generated code")
      }
      emitBlock(b)
      stream.println(quote(getBlockResult(b)))
      stream.println("//#" + s)
      stream.println("}")
    case _ => super.emitNode(sym, rhs)
  }
}


trait DslImpl extends DslExp { q =>
  val codegen = new DslGen {
    val IR: q.type = q
  }
}


abstract class DslDriver[A: Manifest, B: Manifest]
    extends DslSnippet[A, B]
    with DslImpl
    with CompileScala {
  lazy val f = compile(snippet)(manifestTyp[A], manifestTyp[B])
  def precompile: Unit = f
  def precompileSilently: Unit = utils.devnull(f)
  def eval(x: A): B = f(x)
  lazy val code: String = {
    val source = new java.io.StringWriter()
    codegen.emitSource(snippet, "Snippet", new java.io.PrintWriter(source))(
      manifestTyp[A],
      manifestTyp[B]
    )
    source.toString
  }
}

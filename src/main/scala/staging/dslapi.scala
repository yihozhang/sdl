package scala.lms.api

import scala.lms.common._
import scala.reflect.SourceContext
import sdl.staging._

// should this be added to LMS?
trait UtilOps extends Base { this: Dsl =>
  def infix_HashCode[T: Typ](o: Rep[T])(implicit pos: SourceContext): Rep[Long]
  def infix_HashCode(o: Rep[String], len: Rep[Int])(
      implicit v: Overloaded1,
      pos: SourceContext
  ): Rep[Long]
}
trait UtilOpsExp extends UtilOps with BaseExp { this: DslExp =>
  case class ObjHashCode[T: Typ](o: Rep[T])(implicit pos: SourceContext)
      extends Def[Long] { def m = typ[T] }
  case class StrSubHashCode(o: Rep[String], len: Rep[Int])(
      implicit pos: SourceContext
  ) extends Def[Long]
  def infix_HashCode[T: Typ](o: Rep[T])(implicit pos: SourceContext) =
    ObjHashCode(o)
  def infix_HashCode(o: Rep[String], len: Rep[Int])(
      implicit v: Overloaded1,
      pos: SourceContext
  ) = StrSubHashCode(o, len)

  override def mirror[A: Typ](e: Def[A], f: Transformer)(
      implicit pos: SourceContext
  ): Exp[A] =
    (e match {
      case e @ ObjHashCode(a)         => infix_HashCode(f(a))(e.m, pos)
      case e @ StrSubHashCode(o, len) => infix_HashCode(f(o), f(len))
      case _                          => super.mirror(e, f)
    }).asInstanceOf[Exp[A]]
}

trait CGenUtilOps extends CGenBase {
  val IR: UtilOpsExp
  import IR._

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case StrSubHashCode(o, len) => emitValDef(sym, src"hash($o,$len)")
    case _                      => super.emitNode(sym, rhs)
  }
}

trait Dsl
    extends PrimitiveOps
    with NumericOps
    with BooleanOps
    with LiftString
    with LiftPrimitives
    with LiftNumeric
    with LiftBoolean
    with IfThenElse
    with Equal
    with RangeOps
    with OrderingOps
    with MiscOps
    with ArrayOps
    with StringOps
    with SeqOps
    with Functions
    with While
    with StaticData
    with Variables
    with LiftVariables
    with ObjectOps
    with UtilOps {
  import scala.language.implicitConversions
  implicit def repStrToSeqOps(a: Rep[String]) =
    new SeqOpsCls(a.asInstanceOf[Rep[Seq[Char]]])
  override def infix_&&(lhs: Rep[Boolean], rhs: => Rep[Boolean])(
      implicit pos: scala.reflect.SourceContext
  ): Rep[Boolean] =
    __ifThenElse(lhs, rhs, unit(false))
  def unary_!(v: Rep[Boolean])(
      implicit pos: scala.reflect.SourceContext
  ): Rep[Boolean] =
    __ifThenElse(v, unit(false), unit(true))
  override def infix_||(lhs: Rep[Boolean], rhs: => Rep[Boolean])(
      implicit pos: scala.reflect.SourceContext
  ): Rep[Boolean] =
    __ifThenElse(lhs, unit(true), rhs)
  // def infix_&(lhs: Rep[Int], rhs: Rep[Int])(implicit pos: SourceContext) = int_binaryand(lhs, rhs)
  // def int_binaryand(lhs: Rep[Int], rhs: Rep[Int])(implicit pos: SourceContext): Rep[Int]
  def generate_comment(l: String): Rep[Unit]
  def comment[A: Typ](l: String, verbose: Boolean = true)(b: => Rep[A]): Rep[A]
}

trait DslExp
    extends Dsl
    with PrimitiveOpsExpOpt
    with NumericOpsExpOpt
    with BooleanOpsExp
    with IfThenElseExpOpt
    with EqualExpBridgeOpt
    with RangeOpsExp
    with OrderingOpsExp
    with MiscOpsExp
    with EffectExp
    with ArrayOpsExpOpt
    with StringOpsExp
    with SeqOpsExp
    with FunctionsRecursiveExp
    with WhileExp
    with StaticDataExp
    with VariablesExpOpt
    with ObjectOpsExpOpt
    with UtilOpsExp
    with ScannerLowerExp
    with MemoryExp
    with UncheckedHelper {
  override def boolean_or(lhs: Exp[Boolean], rhs: Exp[Boolean])(
      implicit pos: SourceContext
  ): Exp[Boolean] = lhs match {
    case Const(false) => rhs
    case _            => super.boolean_or(lhs, rhs)
  }
  override def boolean_and(lhs: Exp[Boolean], rhs: Exp[Boolean])(
      implicit pos: SourceContext
  ): Exp[Boolean] = lhs match {
    case Const(true) => rhs
    case _           => super.boolean_and(lhs, rhs)
  }

  case class GenerateComment(l: String) extends Def[Unit]
  def generate_comment(l: String) = reflectEffect(GenerateComment(l))
  case class Comment[A: Typ](l: String, verbose: Boolean, b: Block[A])
      extends Def[A]
  def comment[A: Typ](l: String, verbose: Boolean)(b: => Rep[A]): Rep[A] = {
    val br = reifyEffects(b)
    val be = summarizeEffects(br)
    reflectEffect[A](Comment(l, verbose, br), be)
  }

  override def boundSyms(e: Any): List[Sym[Any]] = e match {
    case Comment(_, _, b) => effectSyms(b)
    case _                => super.boundSyms(e)
  }

  override def array_apply[T: Typ](x: Exp[Array[T]], n: Exp[Int])(
      implicit pos: SourceContext
  ): Exp[T] = (x, n) match {
    case (Def(StaticData(x: Array[T])), Const(n)) =>
      val y = x(n)
      if (y.isInstanceOf[Int]) unit(y) else staticData(y)
    case _ => super.array_apply(x, n)
  }

  // TODO: should this be in LMS?
  override def isPrimitiveType[T](m: Typ[T]) =
    (m == typ[String]) ||
      (m == typ[Array[Int]]) ||
      (m == typ[Array[String]]) ||
      super.isPrimitiveType(m)
}

// TODO: currently part of this is specific to the query tests. generalize? move?
trait DslGenC
    extends CGenNumericOps
    with CGenPrimitiveOps
    with CGenBooleanOps
    with CGenIfThenElse
    with CGenEqual
    with CGenRangeOps
    with CGenOrderingOps
    with CGenMiscOps
    with CGenArrayOps
    with CGenStringOps
    with CGenSeqOps
    with CGenFunctions
    with CGenWhile
    with CGenStaticData
    with CGenVariables
    with CGenObjectOps
    with CGenUtilOps {
  val IR: DslExp
  import IR._

  def getMemoryAllocString(count: String, memType: String): String = {
    "(" + memType + "*)malloc(" + count + " * sizeof(" + memType + "));"
  }
  override def remap[A](m: Typ[A]): String = m.toString match {
    case "Array[java.lang.String]" => "char**"
    case "Array[Int]"              => "int32_t*"
    case "java.lang.String"        => "char*"
    case "Array[Char]"             => "char*"
    case "Char"                    => "char"
    case "java.io.File"            => "FILE"
    case _                         => super.remap(m)
  }
  override def format(s: Exp[Any]): String = {
    remap(s.tp) match {
      case "uint16_t"                                => "%c"
      case "bool" | "int8_t" | "int16_t" | "int32_t" => "%d"
      case "int64_t" | "long"                        => "%ld"
      case "float" | "double"                        => "%f"
      case "string"                                  => "%s"
      case "char*"                                   => "%s"
      case "char"                                    => "%c"
      case "void"                                    => "%c"
      case _ =>
        import scala.lms.internal.GenerationFailedException
        throw new GenerationFailedException(
          "CGenMiscOps: cannot print type " + remap(s.tp)
        )
    }
  }
  override def quoteRawString(s: Exp[Any]): String = {
    remap(s.tp) match {
      case "string" => quote(s) + ".c_str()"
      case _        => quote(s)
    }
  }
  // we treat string as a primitive type to prevent memory management on strings
  // strings are always stack allocated and freed automatically at the scope exit
  override def isPrimitiveType(tpe: String): Boolean = {
    tpe match {
      case "char*"     => true
      case "char"      => true
      case "char**"    => true
      case "int32_t*"  => true
      case "int32_t**" => true
      case _           => super.isPrimitiveType(tpe)
    }
  }

  override def quote(x: Exp[Any]) = x match {
    case Const(s: String) =>
      "\"" + s.replace("\"", "\\\"") + "\"" // TODO: more escapes?
    case Const('\n') if x.tp == typ[Char] => "'\\n'"
    case Const('\t') if x.tp == typ[Char] => "'\\t'"
    case Const(0) if x.tp == typ[Char]    => "'\\0'"
    case _                                => super.quote(x)
  }
  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case Equal(a, b) =>
      if (remap(b.tp) == "char*")
        emitValDef(sym, "tpch_strcmp(" + quote(a) + "," + quote(b) + ") == 0;")
      else emitValDef(sym, src"$a == $b")
    case NotEqual(a, b) =>
      if (remap(b.tp) == "char*")
        emitValDef(sym, "tpch_strcmp(" + quote(a) + "," + quote(b) + ") != 0;")
      else emitValDef(sym, src"$a != $b")
    case a @ ArrayNew(n) =>
      val arrType = remap(a.m)
      stream.println(
        arrType + "* " + quote(sym) + " = " + getMemoryAllocString(
          quote(n),
          arrType
        )
      )
    case ArrayApply(x, n) => emitValDef(sym, quote(x) + "[" + quote(n) + "]")
    case ArrayUpdate(x, n, y) =>
      stream.println(quote(x) + "[" + quote(n) + "] = " + quote(y) + ";")
    case PrintLn(s) =>
      stream.println(
        "printf(\"" + format(s) + "\\n\"," + quoteRawString(s) + ");"
      )
    case StringCharAt(s, i) =>
      emitValDef(sym, "%s[%s]".format(quote(s), quote(i)))
    case Comment(s, verbose, b) =>
      stream.println("//#" + s)
      if (verbose) {
        stream.println("// generated code for " + s.replace('_', ' '))
      } else {
        stream.println("// generated code")
      }
      emitBlock(b)
      emitValDef(sym, quote(getBlockResult(b)))
      stream.println("//#" + s)
    case _ => super.emitNode(sym, rhs)
  }
  override def emitSource[A: Typ](
      args: List[Sym[_]],
      body: Block[A],
      functionName: String,
      out: java.io.PrintWriter
  ) = {
    withStream(out) {
      stream.println("""
      #include <fcntl.h>
      #include <errno.h>
      #include <err.h>
      #include <sys/mman.h>
      #include <sys/stat.h>
      #include <stdio.h>
      #include <stdint.h>
      #include <unistd.h>
      #ifndef MAP_FILE
      #define MAP_FILE MAP_SHARED
      #endif
      int fsize(int fd) {
        struct stat stat;
        int res = fstat(fd,&stat);
        return stat.st_size;
      }
      int printll(FILE* f, char* s) {
        while (*s != '\n' && *s != ',' && *s != '\t') {
          fputc(*s++, f);
        }
        return 0;
      }
      long hash(char *str0, int len)
      {
        unsigned char* str = (unsigned char*)str0;
        unsigned long hash = 5381;
        int c;

        while ((c = *str++) && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      size_t tpch_strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '|') && (*str != '\0')) str++;
        return str - start;
      }
      int tpch_strcmp(const char *s1, const char *s2) {
        size_t l1 = tpch_strlen(s1);
        size_t l2 = tpch_strlen(s2);
        if (l1 > l2) l1 = l2;
        return strncmp(s1,s2,l1);
      }
      void Snippet(char*);
      int main(int argc, char *argv[])
      {
        if (argc != 2) {
          printf("usage: query <filename>\n");
          return 0;
        }
        Snippet(argv[1]);
        return 0;
      }

      """)
    }
    super.emitSource[A](args, body, functionName, out)
  }
}

abstract class DslSnippet[A: Manifest, B: Manifest] extends Dsl {
  def snippet(x: Rep[A]): Rep[B]
}

abstract class DslDriverC[A: Manifest, B: Manifest]
    extends DslSnippet[A, B]
    with DslExp { q =>
  val codegen = new DslGenC with CGenScannerLower {
    val IR: q.type = q
  }
  lazy val code: String = {
    implicit val mA = manifestTyp[A]
    implicit val mB = manifestTyp[B]
    val source = new java.io.StringWriter()
    codegen.emitSource(snippet, "Snippet", new java.io.PrintWriter(source))
    source.toString
  }
  def eval(a: A): Unit = { // TBD: should read result of type B?
    val out = new java.io.PrintWriter("/tmp/snippet.c")
    out.println(code)
    out.close
    //TODO: use precompile
    (new java.io.File("/tmp/snippet")).delete
    import scala.sys.process._
    (s"cc -std=c99 -O3 /tmp/snippet.c -o /tmp/snippet": ProcessBuilder).lineStream
      .foreach(Console.println _)
    (s"/tmp/snippet $a": ProcessBuilder).lineStream.foreach(Console.println _)
  }
}

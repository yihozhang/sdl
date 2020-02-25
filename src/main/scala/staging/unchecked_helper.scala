package sdl.staging

import scala.lms.common._
import scala.reflect.SourceContext
import scala.lms.api.Dsl
import scala.lms.internal._
import scala.lms.util._


trait UncheckedHelper extends Dsl with UncheckedOps {

  import scala.language.implicitConversions
  import scala.language.reflectiveCalls

  // to avoid name conflicts
  implicit class richRichQuote(c: StringContext) {
    class QuoteOps(args: Thunk[Rep[Any]]*) {
      def as[T: Typ]: Rep[T] = {
        //reflect(c.s(args map (a => reify(a.eval())):_*))
        def merge(a: List[Any], b: List[Any]): List[Any] = a match {
          case Nil     => Nil
          case x :: xs => x :: merge(b, xs)
        }
        unchecked[T](merge(c.parts.toList, args.toList.map(_.eval())): _*)
      }
    }
    def rawSrc(args: Thunk[Rep[Any]]*) = new QuoteOps(args: _*)
  }

  def array_realloc[T: Typ](
      xs: Rep[Array[T]],
      size: Rep[Int]
  ): Rep[Array[T]] = {
    if (typ[T] == typ[Int])
      rawSrc"(int*)realloc($xs,$size * sizeof(int))".as[Array[T]]
    else if (typ[T] == typ[String])
      rawSrc"(char**)realloc($xs,$size * sizeof(char*))".as[Array[T]]    
    else {
      printf(s"ERROR: realloc for type ${typ[Array[T]]} not implemented\n")
      xs
    }
  }

  def string_hash(x: Rep[String], l: Rep[Long]): Rep[Long] = {
    rawSrc"hash($x, $l)".as[Long]
  }

  def double_to_long(x: Rep[Double]): Rep[Long] = {
    rawSrc"(long) $x".as[Long]
  }

  def atoi(x: Rep[String]): Rep[Int] = {
    rawSrc"atoi($x)".as[Int]
  }

}

// trait ArrayReallocUtils extends Dsl with UncheckedOps {
//     import scala.language.implicitConversions
//     import scala.language.reflectiveCalls
//   implicit def rq(c: StringContext) = new {
//     def raw(args: Thunk[Rep[Any]]*) = new {
//       def as[T: Manifest]: Rep[T] = {
//         //   implicit def typ = mtype(typ[T])
//         //reflect(c.s(args map (a => reify(a.eval())):_*))
//         def merge(a: List[Any], b: List[Any]): List[Any] = a match {
//           case Nil     => Nil
//           case x :: xs => x :: merge(b, xs)
//         }
//         unchecked[T](merge(c.parts.toList, args.toList.map(_.eval())): _*)
//       }
//     }
//   }

//   def array_realloc[T: Manifest](
//       xs: Rep[Array[T]],
//       size: Rep[Int]
//   ): Rep[Array[T]] = {
//     // TODO: proper IR node
//     if (typ[T] == typ[Int])
//       raw"(int*)realloc($xs,$size * sizeof(int))".as[Array[T]]
//     else if (typ[T] == typ[Long])
//       raw"(long*)realloc($xs,$size * sizeof(long))".as[Array[T]]
//     else if (typ[T] == typ[Double])
//       raw"(double*)realloc($xs,$size * sizeof(double))".as[Array[T]]
//     else if (typ[T] == typ[Character])
//       raw"(char*)realloc($xs,$size * sizeof(char))".as[Array[T]]
//     else if (typ[T] == typ[String])
//       raw"(char**)realloc($xs,$size * sizeof(char*))".as[Array[T]]
//     else if (typ[T] == typ[Array[Byte]])
//       raw"(char**)realloc($xs,$size * sizeof(char*))".as[Array[T]]
//     else if (typ[T] == typ[Array[Int]])
//       raw"(int**)realloc($xs,$size * sizeof(int*))".as[Array[T]]
//     else {
//       printf(s"ERROR: realloc for type ${typ[Array[T]]} not implemented\n")
//       xs
//     }
//   }
// }

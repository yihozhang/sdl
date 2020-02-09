import scala.lms.api._

object Main {
  def main(args: Array[String]): Unit = {
    val snippet = new DslDriverC[Int,Int] {
      def snippet(x: Rep[Int]) = {
        val a = NewArray[Int](x)
        a(1) = 1
        a.length
      }
    }
    println(snippet.code)
  }
}
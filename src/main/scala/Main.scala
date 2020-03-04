import scala.lms.api._
import sdl.staging._
import sdl.interpreter._
import scala.lms.common._
import scala.lms.internal.Config
import sdl.parser.ParserUtil

object Main {

  def main(args: Array[String]): Unit = {

    
    def snippet =
      new DslDriverC[String, Unit] with InterpreterUtil with ParserUtil {
        // verbosity = 100
        // sourceinfo = 100
        def readFile(filename: String): String = {
          val source = scala.io.Source.fromFile(filename)
          try source.getLines mkString "\n"
          finally source.close()
        }

        def parseProgram(prog: String): Program =
          DlParser.parseAll(DlParser.program, prog).get

        override def snippet(unused: Rep[String]) = {
          val text = readFile("test/parser/prog1.txt")
          val prog = parseProgram(text)
          new Interpreter(prog).run()
        }
      }
    val out = new java.io.PrintWriter("./test.c")
    out.println(snippet.code)
    out.close
    // System.out.println(snippet.code)
    // snippet.eval("1")
  }
}

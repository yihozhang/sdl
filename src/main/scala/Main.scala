import scala.lms.api._
import sdl.staging._
import sdl.interpreter._
import scala.lms.common._
import sdl.parser.ParserUtil

object Main {

  def main(args: Array[String]): Unit = {

    def snippet =
      new DslDriverC[String, Unit] with InterpreterUtil with ParserUtil {

        def readFile(filename: String): String = {
          val source = scala.io.Source.fromFile(filename)
          try source.getLines mkString "\n"
          finally source.close()
        }

        def parseProgram(prog: String): Program =
          DlParser.parseAll(DlParser.program, prog).get

        override def snippet(unused: Rep[String]) = {
          val text = readFile("test/parser/simple_prog1.txt")
          val prog = parseProgram(text)
          new Interpreter(prog).run()
        }
      }

    println(snippet.code)
  }
}

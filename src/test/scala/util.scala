package sdl.test
import sdl.Parser.DlParser
import sdl.program._
import scala.io.Source

object util {
    def readFile(filename: String): String = {
        val source = scala.io.Source.fromFile("test/parser/prog1.txt")
        try source.getLines mkString "\n" finally source.close()
    }
    
    def parserTestHelper[T](prog: String, target: DlParser.Parser[T]): T = {
        val result = DlParser.parseAll(target, prog).get
        result
    }

    def parseProgram(prog: String): Program = parserTestHelper(prog, DlParser.program)
}
package sdl.test
import sdl.parser.DlParser
import sdl.ast.Program
import scala.io.Source

object util {
    def readFile(filename: String): String = {
        val source = scala.io.Source.fromFile(filename)
        try source.getLines mkString "\n" finally source.close()
    }
    
    def parserTestHelper[T](prog: String, target: DlParser.Parser[T]): T = {
        val result = DlParser.parseAll(target, prog).get
        result
    }

    def parseProgram(prog: String): Program = parserTestHelper(prog, DlParser.program)
}
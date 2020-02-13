package sdl.test
import org.scalatest.FunSuite
import sdl.test.util._

class ProgramSuite extends FunSuite {
  import sdl.Parser._
  test("collect index") {
      val text = readFile("test/parser/prog1.txt")
      val prog = parseProgram(text)
      println(prog.collectIndices)
  }
}
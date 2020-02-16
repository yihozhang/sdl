package sdl.test
import org.scalatest.FunSuite
import sdl.test.util._

class InterpreterSuite extends FunSuite {
  import sdl.util._
  import sdl.ast._
  import sdl.interpreter.Interpreter
  test("load data") {
      val arr = SArray[Array[Element]]()
      val schema = List("parent" -> Type.STR, "child" -> Type.STR)
      val table = Table(schema)
      table.loadFrom("test/parser/data1.txt")
  }
  test("simple load swap and store") {
    val text = readFile("test/parser/simple_prog1.txt")
    val prog = parseProgram(text)
    new Interpreter(prog).run
  }

  test("simple test 2") {
    val text = readFile("test/parser/simple_prog2.txt")
    val prog = parseProgram(text)
    new Interpreter(prog).run
  }
}
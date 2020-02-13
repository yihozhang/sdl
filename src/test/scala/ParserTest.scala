package sdl.test
import scala.io.Source
import org.scalatest.FunSuite
import scala.util.parsing.combinator._

class ParserSuite extends FunSuite {
  import sdl.Parser._
  def parserTestHelper[T](prog: String, target: DlParser.Parser[T]) {
    val result = DlParser.parseAll(target, prog).get
  }
  test("parse identifier") {
    parserTestHelper("person", DlParser.id)
    parserTestHelper("name", DlParser.id)
    parserTestHelper("a", DlParser.id)
    parserTestHelper("@new_MA", DlParser.id)
  }
  test("parse tuple element") {
    parserTestHelper("t1.0", DlParser.tupleElement)
  }
  test("parse declaration") {
    parserTestHelper(
      """
         PROJECT (t1.0, t0.0) INTO @new_MA""",
      DlParser.op
    )
    
    parserTestHelper(
      """FOR t1 IN @delta_MA ON INDEX t1.y = t0.1
         PROJECT (t1.0, t0.0) INTO @new_MA""",
      DlParser.op
    )
  }

  test("parse stmt") {
    val source = scala.io.Source.fromFile("test/parser/stmts1.txt")
    val prog = try source.getLines mkString "\n" finally source.close()
    parserTestHelper(
      prog,
      DlParser.stmts
    )
  }

  test("parse prog") {
    val source = scala.io.Source.fromFile("test/parser/prog1.txt")
    val prog = try source.getLines mkString "\n" finally source.close()
    parserTestHelper(
      prog,
      DlParser.program
    )
  }
}

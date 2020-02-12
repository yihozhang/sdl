package sdl.test
import org.scalatest.FunSuite
import scala.util.parsing.combinator._

class ParserSuite extends FunSuite {
  import sdl.Parser._
  def parserTestHelper[T](prog: String, target: DlParser.Parser[T]) {
    val result = DlParser.parse(target, prog).get
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
}

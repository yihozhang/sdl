package sdl.test
import org.scalatest.FunSuite
import scala.util.parsing.combinator._

class ParserSuite extends FunSuite {
  import sdl.Parser._
  // def parserTestHelper[T](prog: String, target: DlParser.Parser[T]) {
  //   val result = DlParser.parse(target, prog).get
  //   println(result)
  // }
  // test("parse number") {
  //   parserTestHelper("123", DlParser.astNum)
  // }
  // test("parse string") {
  //   parserTestHelper("\"123\"", DlParser.astString)
  // }
  // test("parse identifier") {
  //   parserTestHelper("person", DlParser.astId)
  //   parserTestHelper("name", DlParser.astId)
  //   parserTestHelper("a", DlParser.astId)
  //   parserTestHelper("somebody", DlParser.astId)
  // }
  // test("parse declaration") {
  //   parserTestHelper(
  //     ".decl person(name:number, description:string)",
  //     DlParser.astDeclSchema
  //   )
  //   parserTestHelper(".decl a()", DlParser.astDeclSchema)
  // }
  // test("parse input") {
  //   parserTestHelper(
  //     ".input parent_child(\"DATA/parent_child.facts\")",
  //     DlParser.astDeclInput
  //   )
  // }
  // test("parse rule") {
  //   parserTestHelper(
  //     """p0(x,d) :- parent_child("Priscilla",x), person(x,d).""",
  //     DlParser.astRule
  //   )
  // }
  // test("parse output") {
  //   parserTestHelper(
  //     """.output p0(stdout)""",
  //     DlParser.astDeclOutput
  //   )
  //   parserTestHelper(
  //     """.output p0("hw2-q3-1.ans"")""",
  //     DlParser.astDeclOutput
  //   )
  // }
}

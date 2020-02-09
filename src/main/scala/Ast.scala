package sdl
package object Ast {
  sealed abstract class AstStmt
  case class AstDeclSchema(name: String, schema: List[(String, DataType)]) extends AstStmt
  case class AstDeclInput(name: String, sourceName: String) extends AstStmt
  case class AstRule(head: AstTerm, terms: List[AstTerm]) extends AstStmt
  case class AstDeclOutput(name: String, outputType: OutputType) extends AstStmt

  sealed abstract class OutputType
  object StdOutput extends OutputType
  case class FileOutput(filename: String) extends OutputType

  case class AstTerm(name: String, values: List[AstValue])
  sealed abstract class AstValue
  case class AstNum(value: Int) extends AstValue
  case class AstStr(value: String) extends AstValue
  case class AstVar(name: String) extends AstValue

  type DataType = DataType.Value
  object DataType extends Enumeration {
    val DT_STRING, DT_NUMBER = Value
  }
}
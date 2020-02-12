package sdl.Parser
import scala.util.parsing.combinator._
import sdl.Ast._
/*
object DlParser extends RegexParsers {
  def astStmts: Parser[
    (
        List[AstDeclSchema],
        List[AstDeclInput],
        List[AstRule],
        List[AstDeclOutput]
    )
  ] = {
    rep(astStmt) ^^ { stmts =>
      (
        stmts
          .filter(_.isInstanceOf[AstDeclSchema])
          .asInstanceOf[List[AstDeclSchema]],
        stmts
          .filter(_.isInstanceOf[AstDeclInput])
          .asInstanceOf[List[AstDeclInput]],
        stmts
          .filter(_.isInstanceOf[AstRule])
          .asInstanceOf[List[AstRule]],
        stmts
          .filter(_.isInstanceOf[AstDeclOutput])
          .asInstanceOf[List[AstDeclOutput]]
      )
    }
  }

  def astStmt: Parser[AstStmt] = {
    astDeclSchema | astDeclInput | astRule | astDeclOutput
  }

  def astDeclSchema: Parser[AstDeclSchema] = {
    ".decl" ~> astId ~ "(" ~ astArgList <~ ")" ^^ {
      case tableName ~ _ ~ arglist => AstDeclSchema(tableName, arglist)
    }
  }
  def astDeclInput: Parser[AstDeclInput] = {
    ".input" ~> astId ~ "(" ~ astString <~ ")" ^^ {
      case tableName ~ _ ~ filename => AstDeclInput(tableName, filename)
    }
  }
  def astRule: Parser[AstRule] = {
    astTerm ~ ":-" ~ repsep(astTerm, ",") <~ "." ^^ {
      case head ~ _ ~ terms => AstRule(head, terms)
    }
  }
  def astTerm: Parser[AstTerm] = {
    astId ~ "(" ~ repsep(astValue, ",") ~ ")" ^^ {
      case tableName ~ _ ~ values ~ _ => AstTerm(tableName, values)
    }
  }
  def astValue: Parser[AstValue] = {
    astId ^^ {
      AstVar(_)
    } | astString ^^ {
      AstStr(_)
    } | astNum ^^ {
      AstNum(_)
    }
  }

  def astDeclOutput: Parser[AstDeclOutput] = {
    ".output" ~> astId ~ "(" ~ {
      "stdout" ^^^ StdOutput | astString ^^ {
        FileOutput(_)
      }
    } <~ ")" ^^ {
      case tableName ~ _ ~ output => AstDeclOutput(tableName, output)
    }
  }

  def astId: Parser[String] =
    "[a-zA-Z_][a-zA-Z0-9_]*".r ^^ { id =>
      id.intern()
    }

  def astNum: Parser[Int] =
    "[1-9][0-9]*".r ^^ { value =>
      Integer.valueOf(value)
    }
  def astString: Parser[String] =
    """"([^"]*"?)*"""".r ^^ { id => // "([^"]*\")*"
      id.substring(1, id.size - 1).intern()
    }
  def astDataType: Parser[DataType] = {
    "number" ^^^ DataType.DT_NUMBER | "string" ^^^ DataType.DT_STRING
  }
  def astArgList: Parser[List[(String, DataType)]] = {
    repsep(astId ~ ":" ~ astDataType, ",") ^^ {
      _.map {
        case id ~ _ ~ datatype => (id, datatype)
      }
    }
  }
}
*/
package sdl.Parser
import scala.util.parsing.combinator._
import sdl.Ast._

object DlParser extends RegexParsers {
  def id: Parser[Id] = {
    "[@a-zA-Z_][a-zA-Z0-9_]*".r
  }
  def relId: Parser[RelId] = {
    "[@a-zA-Z_][a-zA-Z0-9_]*".r
  }
  def field: Parser[Field] = {
    "[@a-zA-Z_][a-zA-Z0-9_]*".r
  }

  def num: Parser[Int] = {
    "0|[1-9][0-9]*".r ^^ { x =>
      x.toInt
    }
  }

  def str: Parser[String] = {
    "\"[^\"]\"".r ^^ { s =>
      s.slice(1, s.length - 1)
    }
  }

  def op: Parser[Op] = {
    indexScan | scan | indexChoice | choice | filter | project
  }
  def abstractScan: Parser[(Id, RelId)] = {
    "FOR" ~ id ~ "IN" ~ relId ^^ {
      case _ ~ v ~ _ ~ rel => (v, rel)
    }
  }
  def indexScan: Parser[IndexScan] = {
    abstractScan ~ abstractIndexOp ~ op ^^ {
      case (v, rel) ~ indices ~ child =>
        IndexScan(v, rel, indices, child)
    }
  }
  def scan: Parser[Scan] = {
    abstractScan ~ op ^^ {
      case (v, rel) ~ child => Scan(v, rel, child)
    }
  }

  def indexChoice: Parser[IndexChoice] = {
    "CHOICE" ~ id ~ "IN" ~ relId ~ abstractIndexOp ~ "WHERE" ~ cond ~ op ^^ {
      case _ ~ id ~ _ ~ rel ~ indices ~ _ ~ cond ~ child =>
        IndexChoice(id, rel, cond, indices, child)
    }
  }
  def choice: Parser[Choice] = {
    "CHOICE" ~ id ~ "IN" ~ relId ~ "WHERE" ~ cond ~ op ^^ {
      case _ ~ id ~ _ ~ rel ~ _ ~ cond ~ child =>
        Choice(id, rel, cond, child)
    }
  }
  def filter: Parser[Filter] = {
    "IF" ~> cond ~ op ^^ {
      case cond ~ op => Filter(cond, op)
    }
  }
  def project: Parser[Project] = {
    "PROJECT" ~ "(" ~ rep1sep(expr, ",") ~ ")" ~ "INTO" ~ relId ^^ {
      case _ ~ _ ~ exprs ~ _ ~ _ ~ rel => Project(rel, exprs)
    }
  }

  def abstractIndexOp: Parser[Indices] = {
    "ON" ~ "INDEX" ~> rep1sep(relId ~ "." ~> field ~ "=" ~ expr ^^ {
      case field ~ _ ~ expr => field -> expr
    }, "AND")
  }

  def cond: Parser[Cond] = {
    conjunction | negation | constraint | isEmpty
  }

  // def _true: Parser[True.type] = ???
  // def _false: Parser[False.type] = ???

  def conjunction: Parser[Conjunction] = {
    "(" ~> cond ~ "AND" ~ cond <~ ")" ^^ {
      case lhs ~ _ ~ rhs => Conjunction(lhs, rhs)
    }
  }

  def negation: Parser[Negation] = {
    "(" ~ "NOT" ~> cond <~ ")" ^^ { child =>
      Negation(child)
    }
  }

  def constraint: Parser[Constraint] = {
    "(" ~> expr ~ cstraintOp ~ expr <~ ")" ^^ {
      case lhs ~ op ~ rhs => Constraint(lhs, op, rhs)
    }
  }
  // def doesExist: Parser[DoesExist] = ???

  def isEmpty: Parser[IsEmpty] = {
    "(" ~> relId <~ "=" ~ "∅" ~ ")" ^^ { rel =>
      IsEmpty(rel)
    }
  }

  def expr: Parser[Expr] = {
    tupleElement | const | binaryExpr
  }

  def tupleElement: Parser[TupleElement] = {
    relId ~ "." ~ num ^^ {
      case rel ~ _ ~ num => TupleElement(rel, num)
    }
  }
  def const: Parser[Const] = {
    num ^^ {
      case num => Const(IntElement(num))
    } | str ^^ {
      case str => Const(StringElement(str))
    }
  }
  def binaryExpr: Parser[BinaryExpr] = {
    "(" ~> expr ~ exprOp ~ expr <~ ")" ^^ {
      case lhs ~ op ~ rhs => BinaryExpr(lhs, op, rhs)
    }
  }

  def cstraintOp: Parser[CstraintOp] = {
    "=" ^^^ CstraintOp.EQ |
      "!=" ^^^ CstraintOp.NE |
      ">" ^^^ CstraintOp.GT |
      ">=" ^^^ CstraintOp.GE |
      "<" ^^^ CstraintOp.LT |
      "<=" ^^^ CstraintOp.LE
  }

  def exprOp: Parser[ExprOp] = {
    "+" ^^^ ExprOp.ADD |
      "-" ^^^ ExprOp.SUB |
      "*" ^^^ ExprOp.MUL |
      "/" ^^^ ExprOp.DIV
  }
}

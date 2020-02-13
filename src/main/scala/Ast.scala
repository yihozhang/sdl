package sdl

package object Ast {

  type Id = String
  type RelId = String
  type Field = String
  type Indices = Map[Field, Expr]
  case class IndexSchema(rel: RelId, fields: List[Field])

  case class Decl(rel: RelId, schema: Map[String, Type])

  sealed abstract class Stmt {
    def acceptOp(visitor: Op => Unit) = ()
  }
  case class Load(rel: RelId, filename: String) extends Stmt
  case class Store(rel: RelId, filename: String) extends Stmt
  case class Clear(rel: RelId) extends Stmt
  case class Swap(relA: RelId, relB: RelId) extends Stmt
  case class Query(op: Op) extends Stmt {
    override def acceptOp(visitor: Op => Unit) {
      this.op.accept(visitor)
    }
  }
  case class Loop(stmt: List[Stmt]) extends Stmt {
    override def acceptOp(visitor: Op => Unit) {
      this.stmt.foreach(_.acceptOp(visitor))
    }
  }
  case class Exit(cond: Cond) extends Stmt

  sealed abstract class Op {
    def accept(visitor: Op => Unit) {
      visitor(this)
    }
  }
  sealed abstract class NestedOp extends Op {
    val child: Op
    override def accept(visitor: Op => Unit) {
      visitor(this)
      child.accept(visitor)
    }
  }
  sealed trait IndexedOp extends Op {
    val indices: Indices
    val indexedOn: RelId
  }
  sealed abstract class AbstractScan extends NestedOp {
    val v: Id
    val rel: RelId
  }
  case class IndexScan(v: Id, rel: RelId, indices: Indices, child: Op)
      extends AbstractScan
      with IndexedOp {
    override val indexedOn = rel
  }
  case class Scan(v: Id, rel: RelId, child: Op) extends AbstractScan

  sealed abstract class AbstractChoice extends NestedOp {
    val v: Id
    val rel: RelId
    val cond: Cond
  }
  case class IndexChoice(
      v: Id,
      rel: RelId,
      cond: Cond,
      indices: Indices,
      child: Op
  ) extends AbstractChoice
      with IndexedOp {
    override val indexedOn: RelId = rel
  }
  case class Choice(v: Id, rel: RelId, cond: Cond, child: Op)
      extends AbstractChoice

  case class Filter(cond: Cond, child: Op) extends NestedOp
  case class Project(rel: RelId, exprs: List[Expr]) extends Op

  sealed abstract class Cond
  // case object True extends Cond
  // case object False extends Cond
  case class Conjunction(lhs: Cond, rhs: Cond) extends Cond
  case class Negation(child: Cond) extends Cond
  case class Constraint(lhs: Expr, op: CstraintOp, rhs: Expr) extends Cond
  case class DoesExist(exprs: List[Expr], rel: RelId) extends Cond
  case class IsEmpty(rel: RelId) extends Cond

  sealed abstract class Expr
  case class TupleElement(rel: RelId, elem: Int) extends Expr
  case class Const(value: Element) extends Expr
  case class BinaryExpr(lhs: Expr, op: ExprOp, rhs: Expr) extends Expr

  type CstraintOp = CstraintOp.Value
  object CstraintOp extends Enumeration {
    val EQ, NE, LT, LE, GE, GT = Value
  }
  type ExprOp = ExprOp.Value
  object ExprOp extends Enumeration {
    val ADD, SUB, MUL, DIV = Value
  }
  sealed abstract class Element
  case class IntElement(value: Int) extends Element
  case class StringElement(value: String) extends Element

  type AggOp = AggOp.Value
  object AggOp extends Enumeration {
    val Max, Min, Count, Sum = Value
  }

  type Type = Type.Value
  object Type extends Enumeration {
    val NUM, STR = Value
  }
}

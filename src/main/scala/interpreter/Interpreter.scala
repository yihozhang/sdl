package sdl.interpreter
import sdl.ast._
import sdl.util._
import java.io.File
import java.util.Scanner
import scala.collection.immutable.Nil
class Interpreter(program: Program) {
  val DEBUG = false
  type Env = Map[RelId, Decl]
  val initial = Map[Id, Tuple]()
  def run() {
    val env = program.env
    val tableManager = new TableManager(env)

    val indices = program.collectIndices
    program.stmts.foreach(eval(_)(tableManager))
  }
  private def eval(stmt: Stmt)(implicit tableManager: TableManager) {
    if (DEBUG) println("running" + stmt.toString())
    stmt match {
      case Load(rel, filename)  => tableManager(rel).loadFrom(filename)
      case Store(rel, filename) => tableManager(rel).storeTo(filename)
      case Clear(rel)           => tableManager(rel).clear()
      case Swap(relA, relB) =>
        Table.swap(tableManager(relA), tableManager(relB))
      case Query(op) => eval(op)(tableManager, initial)
      case Loop(stmts) => {
        var flag = true
        def unroll(stmts: List[Stmt]) {
          stmts match {
            case head :: tl => {
              head match {
                case Exit(cond) =>
                  if (eval(cond)(tableManager, initial)) {
                    flag = false
                  } else {
                    unroll(tl)
                  }
                case _ => {
                  eval(head)
                  unroll(tl)
                }
              }
            }
            case _ => ()
          }
        }
        while (flag) {
          unroll(stmts)
        }
      }
      case _ => throw new IllegalStateException("should not reach")
    }
  }
  private def eval(op: Op)(
      implicit tableManager: TableManager,
      env: Map[Id, Tuple]
  ) {
    if (DEBUG) println("running" + op.toString())
    op match {
      case IndexScan(v, rel, indices, child) => ???
      case Scan(v, rel, child) => {
        tableManager(rel).foreach { s: Tuple =>
          eval(child)(tableManager, env + (v -> s))
        }
      }
      case IndexChoice(v, rel, cond, indices, child) => ???
      case Choice(v, rel, cond, child) => {
        var i = 0
        val tab = tableManager(rel);
        while (i < tab.length) {
          eval(cond)(tableManager, env + (v -> tab.get(i)))
          i += 1
        }
      }
      case Filter(cond, child) => {
        if (eval(cond)) {
          eval(child)
        }
      }
      case Project(rel, exprs) => {
        tableManager(rel).push(exprs.map(eval(_)):_*)
      }
    }
  }
  private def eval(
      cond: Cond
  )(implicit tableManager: TableManager, env: Map[Id, Tuple]): Boolean = {
    if (DEBUG) println("running" + cond.toString())
    cond match {
      case Conjunction(lhs, rhs) => eval(lhs) && eval(rhs)
      case Negation(child)       => !eval(child)
      case Constraint(lhs, op, rhs) => {
        assert(op == CstraintOp.EQ)
        eval(lhs) == eval(rhs)
      }
      case DoesExist(exprs, rel) => {
        val length = exprs.length
        val values = new Array[Element](length)
        for ((expr, i) <- exprs.zipWithIndex) {
          values(i) = eval(expr)
        }
        var result = false
        tableManager(rel).stopableForeach { tup =>
          {
            var flag = true
            var i = 0
            while (flag && i < length) {
              if (tup(i) != values(i)) {
                flag = false
              }
              i += 1
            }
            if (flag) {
              result = true
            }
            !flag // flag=true => not continue
          }
        }
        result
      }
      case IsEmpty(rel) => {
        tableManager(rel).length == 0
      }
    }
  }
  private def eval(
      expr: Expr
  )(implicit tableManager: TableManager, env: Map[Id, Tuple]): Element = {
    if (DEBUG) println("running" + expr.toString())
    expr match {
      case TupleElement(id, elem)  => env(id)(elem)
      case Const(value)             => value
      case BinaryExpr(lhs, op, rhs) => {
        val lval = eval(lhs)
        val rval = eval(rhs)
        op match {
          case ExprOp.ADD => ???
          case ExprOp.SUB => ???
          case ExprOp.MUL => ???
          case ExprOp.DIV => ???
        }
      }
    }
  }
}

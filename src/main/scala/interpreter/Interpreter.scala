package sdl.interpreter
import sdl.ast._
import sdl.util._
import scala.lms.common._
import scala.reflect.SourceContext
import java.io.File
import java.util.Scanner
import scala.collection.immutable.Nil
import scala.lms.api._
trait InterpreterUtil
    extends DslExp
    with TableUtil
    with ProgramUtil {
  implicit def anyTyp: Typ[Any] = manifestTyp
  class Interpreter(program: Program) {
    val DEBUG = false
    type Env = Map[RelId, Decl]
    val initial = Map[Id, Tuple]()
    def run() {
      val env = program.env
      val indices = program.collectIndices
      val tableManager = new TableManager(env, indices)

      program.stmts.foreach(eval(_)(tableManager))
    }
    private def eval(stmt: Stmt)(implicit tableManager: TableManager) {
      if (DEBUG) println("running" + stmt.toString())
      stmt match {
        case LoadStmt(rel, filename)  => tableManager(rel).loadFrom(filename)
        case StoreStmt(rel, filename) => tableManager(rel).storeTo(filename)
        case ClearStmt(rel)           => tableManager(rel).clear()
        case SwapStmt(relA, relB) =>
          Table.swap(tableManager(relA), tableManager(relB))
        case QueryStmt(op) => eval(op)(tableManager, initial)
        case LoopStmt(stmts) => {
          var flag = true
          def unroll(stmts: List[Stmt]) {
            stmts match {
              case head :: tl => {
                head match {
                  case ExitStmt(cond) =>
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
        case IndexScan(v, rel, indices, child) => {
          val fields = indices.toList.map(_._1)
          val values = indices.toList.map(_._2).map(eval(_))
          tableManager(rel)(fields, values:_*).foreach { tup =>
            eval(child)(tableManager, env + (v -> tup))
          }
        }
        case Scan(v, rel, child) => {
          tableManager(rel).foreach { s =>
            eval(child)(tableManager, env + (v -> s))
          }
        }
        case IndexChoice(v, rel, cond, indices, child) => {
          val fields = indices.toList.map(_._1)
          val values = indices.toList.map(_._2).map(eval(_))
          tableManager(rel)(fields, values:_*).stopableForeach { tup =>
            eval(cond)(tableManager, env + (v -> tup))
          }
        }
        case Choice(v, rel, cond, child) => {
          tableManager(rel).stopableForeach { tup =>
            eval(cond)(tableManager, env + (v -> tup))
          }
        }
        case Filter(cond, child) => {
          if (eval(cond)) {
            eval(child)
          }
        }
        case Project(rel, exprs) => {
          tableManager(rel).push(exprs.map(eval(_)): _*)
        }
      }
    }
    private def eval(
        cond: Cond
    )(
        implicit tableManager: TableManager,
        env: Map[Id, Tuple]
    ): Rep[Boolean] = {
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
          val values = NewArray[Any](length)
          for ((expr, i) <- exprs.zipWithIndex) {
            values(i) = eval(expr)
          }
          var result = false
          tableManager(rel).stopableForeach { tup =>
            {
              var flag = true
              var i: Int = 0
              while (flag && i < length) {
                if (tup(i) != values(i)) {
                  flag = false
                }
                i += 1
              }
              if (flag) {
                result = true
              }
              flag // flag=false => not continue
            }
          }
          result
        }
        case IsEmpty(rel) => {
          tableManager(rel).isEmpty
        }
      }
    }
    private def eval(
        expr: Expr
    )(implicit tableManager: TableManager, env: Map[Id, Tuple]): Rep[Any] = {
      if (DEBUG) println("running" + expr.toString())
      expr match {
        case TupleElement(id, elem) => env(id)(elem)
        case ConstValue(value)           => unit(value)
        case BinaryExpr(lhs, op, rhs) => {
          val lval = eval(lhs).asInstanceOf[Rep[Int]]
          val rval = eval(rhs).asInstanceOf[Rep[Int]]
          op match {
            case ExprOp.ADD => lval + rval
            case ExprOp.SUB => lval - rval
            case ExprOp.MUL => lval * rval
            case ExprOp.DIV => lval / rval
          }
        }
      }
    }
  }
}

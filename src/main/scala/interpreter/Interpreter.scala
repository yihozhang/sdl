package sdl.interpreter

import sdl.ast._
import sdl.util._
import java.io.File
import java.util.Scanner
import scala.collection.immutable.Nil
class Interpreter(program: Program) {
  type Env = Map[RelId, Decl]
  def run() {
    val env = program.env
    val tableManager = new TableManager(env)

    val indices = program.collectIndices

    for (stmt <- program.stmts) {
      eval(stmt, tableManager)

    }

  }
  private def eval(stmt: Stmt, tableManager: TableManager) {
    stmt match {
      case Load(rel, filename)  => tableManager(rel).loadFrom(filename)
      case Store(rel, filename) => tableManager(rel).storeTo(filename)
      case Clear(rel)           => tableManager(rel).clear()
      case Swap(relA, relB) =>
        Table.swap(tableManager(relA), tableManager(relB))
      case Query(op) => eval(op, tableManager)
      case Loop(stmts) => {
        var flag = true
        def unroll(stmts: List[Stmt]) {
          stmts match {
            case head :: tl => {
              head match {
                case Exit(cond) =>
                  if (eval(cond)) {
                    flag = false
                  } else {
                    unroll(tl)
                  }
                case _ => {
                  eval(head, tableManager)
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
  private def eval(op: Op, tableManager: TableManager)(
      implicit env: Map[Id, RelId]
  ) {
    op match {
      case IndexScan(v, rel, indices, child)         => ???
      case Scan(v, rel, child)                       => ???
      case IndexChoice(v, rel, cond, indices, child) => ???
      case Choice(v, rel, cond, child)               => ???
      case Filter(cond, child)                       => ???
      case Project(rel, exprs)                       => ???
    }
  }
  private def eval(cond: Cond): Boolean = {
    cond match {
      case Conjunction(lhs, rhs)    => eval(lhs) && eval(rhs)
      case Negation(child)          => !eval(child)
      case Constraint(lhs, op, rhs) => ???
      case DoesExist(exprs, rel)    => ???
      case IsEmpty(rel)             => ???
    }
  }
  private def eval(expr: Expr): Element = {
    expr match {
      case TupleElement(rel, elem)  => ???
      case Const(value)             => value
      case BinaryExpr(lhs, op, rhs) => ???
    }
  }
}

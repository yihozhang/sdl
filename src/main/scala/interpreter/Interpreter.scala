package sdl.interpreter

import sdl.ast._
import sdl.util._
import java.io.File
import java.util.Scanner
class Interpreter(program: Program) {
  type Env = Map[RelId, Decl]
  def run() {
    val env = program.env
    val tableManager = new TableManager(env)  
    
    val indices = program.collectIndices

    for (stmt <- program.stmts) {
      stmt match {
        case Load(rel, filename) => tableManager(rel).loadFrom(filename)
        case Store(rel, filename) => tableManager(rel).storeTo(filename)
        case Clear(rel) => tableManager(rel).clear()
        case Swap(relA, relB) => Table.swap(tableManager(relA), tableManager(relB))
        case Query(op) => ???
        case Loop(stmts) => ???
        case Exit(stmts) => ???
      }
    }

  }
  def eval(program: Program) {}
  private def eval(stmt: Stmt) {}
  private def eval(op: Op) {
    ???
  }
  private def eval(cond: Cond): Boolean = ???
  private def eval(expr: Expr): Element = ???
}

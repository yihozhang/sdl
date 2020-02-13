package sdl.program

import sdl.Ast._
import sdl.program._

object Interpreter {
    type Env = Map[String, Decl]
    def int(program: Program) {
        ???
    }
    private def int(stmt: Stmt) {

    }
    private def int(op: Op) {
        ???
    }
    private def eval(cond: Cond): Boolean = ???
    private def eval(expr: Expr): Element = ???

}
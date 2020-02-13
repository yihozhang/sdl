package sdl.program

import sdl.Ast._
import sdl.Parser.DlParser

case class Program(
    env: Map[RelId, Decl],
    stmts: List[Stmt]
)
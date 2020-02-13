package sdl.program

import sdl.Ast._
import sdl.Parser.DlParser
import scala.collection.mutable

case class Program(env: Map[RelId, Decl], stmts: List[Stmt]) {
  lazy val collectIndices: List[Indices] = {
    val list = new mutable.ListBuffer[Indices]()
    stmts
      .filter(_.isInstanceOf[Query])
      .foreach(_.asInstanceOf[Query].op.accept { op =>
        if (op.isInstanceOf[IndexedOp]) {
          list.append(op.asInstanceOf[IndexedOp].indices)
        }
      })
    list.toList
  }
}

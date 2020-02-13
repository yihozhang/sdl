package sdl.program

import sdl.Ast._
import sdl.Parser.DlParser
import scala.collection.mutable

case class Program(env: Map[RelId, Decl], stmts: List[Stmt]) {
  lazy val collectIndices: List[IndexSchema] = {
    val list = new mutable.ListBuffer[IndexSchema]()
    stmts
      .foreach(_.acceptOp { op =>
        if (op.isInstanceOf[IndexedOp]) {
          val indexedOp = op.asInstanceOf[IndexedOp]
          val rel = indexedOp.indexedOn
          val fields = indexedOp.indices.keys.toList
          list.append(IndexSchema(rel, fields))
        }
      })
    list.toList.distinct
  }
}

package sdl.ast

import scala.collection.mutable
import scala.lms.api.Dsl
trait ProgramUtil extends Dsl with AstUtil {
  case class Program(env: Map[RelId, Decl], stmts: List[Stmt]) {
    lazy val collectIndices: List[IndexSchema] = {
      val list = new mutable.ListBuffer[IndexSchema]()
      stmts
        .foreach(_.acceptOp { op =>
          if (op.isInstanceOf[IndexedOp]) {
            val indexedOp = op.asInstanceOf[IndexedOp]
            val rel = indexedOp.indexedOn
            val fields = indexedOp.indices.map(_._1)
            list.append(IndexSchema(rel, fields))
          }
        })
      list.toList.distinct
    }
  }
}
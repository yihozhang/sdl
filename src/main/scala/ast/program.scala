package sdl.ast

import scala.collection.mutable
import scala.lms.api.Dsl
trait ProgramUtil extends Dsl with AstUtil {
  case class Program(env: Map[RelId, Decl], stmts: List[Stmt]) {
    lazy val collectIndices: List[IndexSchema] = {
      val list = new mutable.ListBuffer[IndexSchema]()
      // val list = new mutable.ListBuffer[(RelId, List[Field])]()
      stmts
        .foreach(_.acceptOp { op =>
          if (op.isInstanceOf[IndexedOp]) {
            val indexedOp = op.asInstanceOf[IndexedOp]
            val rel = indexedOp.indexedOn
            val fields = indexedOp.indices.map(_._1)
            list.append(IndexSchema(rel, fields))
          }
        })
      val distinctList = list.distinct
      // naive solution that only works for new/delta tables
      def merge(stmts: List[Stmt]) {
        stmts.foreach { stmt =>
          {
            stmt match {
              case SwapStmt(relA, relB) => {
                val listA = list.filter(_.rel == relA)
                val listB = list.filter(_.rel == relB)
                distinctList.appendAll(
                  listA.map(schema => IndexSchema(relB, schema.fields))
                )
                distinctList.appendAll(
                  listB.map(schema => IndexSchema(relA, schema.fields))
                )
              }
              case LoopStmt(stmts) => merge(stmts)
              case _               => ()
            }
          }
        }
      }
      merge(stmts)
      distinctList.toList.distinct
    }
  }
}

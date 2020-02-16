package sdl.staging

import java.io.BufferedWriter
import java.io.FileWriter
import java.io.File

class Printer(filename: String) {
  val bw = new BufferedWriter(new FileWriter(new File(filename)))
  def write(s: String) {
    bw.write(s)
  }
  def close = bw.close
}

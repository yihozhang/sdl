package sdl.util

case class Tuple(arr: SArray, offset: Int, tupleSize: Int) {
    def apply(i: Int) = arr(offset + i)
}
package com.dsa.scala.functionalDataStructuresAndAlgorithms

object MergeSortGeneric {
  def main (args: Array[String]): Unit = {
    val inputList = List(1, 9, 2, 7, 3, 6, 8, 5)

    val mergetSort_ASC_int = mergeSort((x: Int, y: Int) => x < y) _
    val mergetSort_DESC_int = mergeSort((x: Int, y: Int) => x > y) _
    val mergetSort_ASC_Double = mergeSort((x: Double, y: Double) => x < y) _
    val mergetSort_DESC_Double = mergeSort((x: Double, y: Double) => x > y) _

    val sortedList_ASC = mergetSort_ASC_int(inputList)
    val sortedList_DESC = mergetSort_DESC_int(inputList)

    println(sortedList_ASC)  // List(1, 2, 3, 5, 6, 7, 8, 9)
    println(sortedList_DESC) // List(9, 8, 7, 6, 5, 3, 2, 1)

    val inputListDouble = inputList.map(_.toDouble)

    val sortedList_ASC_Double = mergetSort_ASC_Double(inputListDouble)
    val sortedList_DESC_Double = mergetSort_DESC_Double(inputListDouble)

    println(sortedList_ASC_Double)   // List(1.0, 2.0, 3.0, 5.0, 6.0, 7.0, 8.0, 9.0)
    println(sortedList_DESC_Double)  // List(9.0, 8.0, 7.0, 6.0, 5.0, 3.0, 2.0, 1.0)

  }


  def mergeSort[T] (min: (T, T) => Boolean)(ls: List[T]): List[T] = {
    def merge (xs: List[T], ys: List[T]): List[T] = {
      (xs, ys) match {
        case (_, Nil) => xs
        case (Nil, _) => ys
        case (x :: xs1, y :: ys1) =>
          if (min(x, y)) x :: merge(xs1, ys) else y :: merge(xs, ys1)
      }
    }

    val n = ls.length / 2
    if (n == 0) ls
    else {
      val (ys, zs) = ls.splitAt(n)
      merge(mergeSort(min)(ys), mergeSort(min)(zs))
    }
  }
}

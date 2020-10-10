package com.dsa.scala

object InsertionSort {
  def main (args: Array[String]): Unit = {

    val intArray = Array(20, 35, -15, 7, 55, 1, -22)
    println("**********InsertionSort Scala**********")
    println("Unsorted array")

    var i = 0

    for (firstUnsortedIndex <- 1 until intArray.length by 1) {
      var newElement = intArray(firstUnsortedIndex)

      i = firstUnsortedIndex
      for (i <- firstUnsortedIndex until 0 by 1 if intArray(i - 1) > newElement) {
        intArray(i) = intArray(i - 1)
      }
      intArray(i) = newElement
    }
    println("Sorted array - By Insertion sort")
    insertionSort(intArray.toList).foreach(println)
  }

  def insertionSort[A] (la: List[A])(implicit ord: Ordering[A]): List[A] = {
    println("inside insertionSort method")

    def insert (la: List[A], a: A) = {
      val (h, t) = la.span(ord.lt(_, a))
      h ::: (a :: t)
    }

    la./:(List[A]()) { (acc, a) => insert(acc, a) }
  }

}

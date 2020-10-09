//Selection sort in scala
object SelectionSortAscApp {

  //main function
  def main(args: Array[String]): Unit = {
  
    //list to be sorted using selection sort
    println(selectionSortAsc(List(5,3,2,8,7)))
    
    println(selectionSortAsc(List("k","d","c","a","q")))
    
  }
  
  //Selection sort algorithm
  /*1. Find the smallest element, or largest element if doing descending order, in the list and swap with the first element.
    2. In the second pass, find the smallest element in the remaining list, which is a sublist of the given list that doesn’t have the global smallest element.
    3. Swap the smallest element with the lowest index in the sublist if the lowest index element is greater than this smallest element.
    4. Continue the above steps until two elements are left in the list, which is the final pass, requiring only one comparison. Swap if the element at the lower index is greater than the element at the higher index. This completes selection sort.
  */
  
  def selectionSortAsc[T <% Ordered[T]](myData: List[T]):
  List[T] = myData match {
  
    case Nil => Nil
    
    case head :: Nil => List(head)
    
    case head :: tail => {
    
      val minElem = tail.min
      
      val indexOfMinElem = tail.indexOf(minElem)
      
      if(head <= minElem) {
      
        head :: selectionSortAsc(tail)
        } else {
          val (tailHalf1, tailHalf2) =  tail.splitAt(indexOfMinElem)
          
          tailHalf2.head :: selectionSortAsc(tailHalf1 ::: head :: tailHalf2.tail)
          
          }
       }
  }
}

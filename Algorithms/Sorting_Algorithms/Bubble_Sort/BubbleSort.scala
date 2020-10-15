object BubbleSortAscApp {

  //main function
  def main(args: Array[String]): Unit = {
  
    //Passing list to be sorted to bubble sort function
    println(bubbleSortAsc(List(3,1,6,8,2)))
    
    println(bubbleSortAsc(List("z", "c", "a", "b")))
    
  }
  
  // Bubble sort function
  def bubbleSortAsc[T <% Ordered[T]](myData: List[T]):
    List[T] = myData match {
    
      case Nil => Nil
      case _ => {
       
        val (max, remainingData) = calcMax(myData)
      
        bubbleSortAsc(remainingData) ::: List(max)
    
      }
    }
    
    //calculating max each iteration
  def calcMax[T <% Ordered[T]](myData: List[T]): (T,List[T]) = myData match {
  
      case (Nil) => (null.asInstanceOf[T], Nil)
      
      case (head :: Nil) => (head, Nil)
      
      case (head :: tail) => {
      
        val (tailMax, tailRemaining) = calcMax(tail)
        
        if (tailMax >= head) (tailMax, head :: tailRemaining)
        
        else (head, tailMax :: tailRemaining)
      }
  }
}

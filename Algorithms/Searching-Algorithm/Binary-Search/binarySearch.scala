
object GFG{ 
  
// Creating Binary Search function 
def RecursiveBinarySearch(arr: Array[Int], 
                          Element_to_Search: Int) 
                         (low: Int = 0, 
                          high: Int = arr.length - 1): Int = 
{ 
                                    
    if (low > high)  
        return -1
      
    var middle = low + (high - low) / 2
      
    // If element found 
    if (arr(middle) == Element_to_Search) 
        return middle 
      
    else if (arr(middle) > Element_to_Search) 
        return RecursiveBinarySearch(arr,  
               Element_to_Search)(low, middle - 1) 
      
    // Searching in the right half 
    else
        return RecursiveBinarySearch(arr,  
               Element_to_Search)(middle + 1, high) 
} 
  
// Creating main function 
def main(args: Array[String]){ 
      
    var index = RecursiveBinarySearch(Array(1, 2, 3, 4, 55,  
                                            65, 75), 4)(0, 6); 
      
    // If value not found  
    if(index == -1) 
       print("Cannot be Found") 
          
    // Else print the index where the value is found 
    else
       print("Found element at Index = " + index) 
} 
} 

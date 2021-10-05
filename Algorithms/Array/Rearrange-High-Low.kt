// main function
fun main(args: Array<String>) {
  
  // pre defined array
    val arr=arrayOf(3, 6, 5, 10, 7, 20)
    
    // size of array
    val n=arr.size
  
  // sort the array
    arr.sort()
    
    // swap the alternate positions and increment in steps of 2
    for (i in 0 until n step 2)
    {
        arr[i]=arr[i]+arr[i+1];
        arr[i+1]=arr[i]-arr[i+1];
        arr[i]=arr[i]-arr[i+1];
    }
    
    // output the array
    for(i in 0 until n)
    println(arr[i])
    
}
/* 
    Output:
            5
            3
            7
            6
            20
            10
*/

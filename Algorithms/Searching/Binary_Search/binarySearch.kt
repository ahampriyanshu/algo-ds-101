fun binarySearch(arr: List<Int>, lo: Int, hi: Int, target: Int): Int{
    //base case: if the left index crosses right index
    //it means target is not present
    if(lo > hi)return -1

    //calculate the middle index of the current range [lo, hi]
    val mid = lo + (hi - lo)/2

    //return the index if the target is present at that index
    if(arr[mid] == target)
        return mid
    
    //do a recursive binary search on the basis of the whether the found element is 
    //lesser or greater than the target
    return if(arr[mid] < target)
            binarySearch(arr, mid+1, hi, target)
           else 
            binarySearch(arr, lo, mid - 1, target)
}

fun main(){
    //read the input array
    val arr = readLine()!!.split(' ').map{it.toInt()}
    //read the target to be found
    val target = readLine()!!.toInt()
    //do a binary search in the range of index [0, arr.size - 1]
    val index = binarySearch(arr, 0, arr.size - 1, target)
    
    //if the target if not in the array
    if(index == -1)
        println("$target not found")
        
    //if target is present in the array prints its index
    //note: if there are multiple occurences of the target, the index could be any of     //those
    else println("$target found at index $index")
}
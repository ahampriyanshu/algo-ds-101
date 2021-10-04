/*
Intuition:
->for every left we keep track of leftMax and add leftMax - heights[left] to our answer because we know that left has crossed leftMax by passing the condition heights[left] <= heights[right].
->so we can surely say that on the right-side of the left there is atleast a building a height of leftMax or more. So the water stored is min(leftMax, righMax) - heights[left],
but since leftMax would be lesser than equal to rightMax we can just write leftMax - heights[left]
->other wise left would have never crossed the leftMax
->Same goes for right and rightMax

TC: O(N) SC: O(1)
*/
fun getTrappedWater(heights: List<Int>): Int{
    //two pointers left and right to traverse the array
    //two pointers to keep track of leftMax and rightMax height for the current index
    var (left, right, leftMax, rightMax) = intArrayOf(0,heights.size-1,0,0)
    
    //to store the resultant answer
    var totalWaterTrapped = 0
    
    while(left <= right){
        if(heights[left] <= heights[right]){
            leftMax = maxOf(leftMax, heights[left])
            totalWaterTrapped += leftMax - heights[left]
            left++
        }else{
            rightMax = maxOf(rightMax, heights[right])
            totalWaterTrapped += rightMax - heights[right]
            right--
        }
    }
    return totalWaterTrapped
}
fun main(){
    //reading input heights of the buildings
    val heights = readLine()!!.split(' ').map{it.toInt()}
    
    //Calculate the total water trapped between these buildings
    val totalWaterTrapped = getTrappedWater(heights)
    
    //print the corresponding output
    println(totalWaterTrapped)
}
import java.util.*

/*Naive Approach: Check for all pairs if they adds up to the target or not
TC: O(n*n) SC: O(1)
*/
fun findTwoSumNaive(nums: List<Int>, target: Int): IntArray{
    val n = nums.size
    for(i in 0 until n){
        for(j in (i+1) until n){
            if(nums[i] + nums[j] == target)
                return intArrayOf(nums[i], nums[j])
        }
    }
    return intArrayOf(-1, -1)
}

/*Better Approach: Sort the given array
->create two pointers one of which points to the first element and another one to the last element.
->check if both the values pointed to by these pointers adds up to the target or not.
->if yes, return the result.
->otherwise, if the sum is lesser than the target increment left pointer
->           otherwise decrement the right pointer.
->The above intuition works because the array is sorted.
TC: O(nlogn) SC: O(n)
*/
fun findTwoSumBetter(nums: List<Int>, target: Int): IntArray{
    Collections.sort(nums)
    var (lo, hi) = Pair(0, nums.size - 1)
    while(lo < hi){
        val sum = nums[lo] + nums[hi]
        if(sum == target){
            return intArrayOf(nums[lo], nums[hi]);
        }
        if(sum < target) lo++ else hi--
    }
    return intArrayOf(-1, -1)
}

/*Optimal Approach: 
->Use a hashmap to store the numbers as you traverse.
->At any point if you had added a value equal to the target - current_number in the hashmap.
->Then we have our ans as {current_number, target - current_number} which adds up to the target value.
->otherwise return {-1, -1} as the result.
TC: O(n) SC: O(n)
considering the hashmap works in O(1) on an average.
*/
fun findTwoSumOptimal(nums: List<Int>, target: Int): IntArray{
    val map = mutableMapOf<Int, Boolean>()
    for(num in nums){
        if(map.containsKey(target - num))
            return intArrayOf(target - num, num)
        map[num] = true
    }
    return intArrayOf(-1, -1)
}

//main function
fun main(){
    //get the input array
    val nums = readLine()!!.split(' ').map{it.toInt()}

    //get the target value
    val target = readLine()!!.toInt()

    //a pair of values to store the result
    val values = findTwoSumOptimal(nums, target)

    //if both the values of the result are -1
    //it means no such pair exists that adds up to the target value
    //otherwise, print a valid pair of values
    if(values[0] == -1 && values[1] == -1)
        println("No such pair exists")
    else 
        println("${values[0]} and ${values[1]} adds up to $target")
}
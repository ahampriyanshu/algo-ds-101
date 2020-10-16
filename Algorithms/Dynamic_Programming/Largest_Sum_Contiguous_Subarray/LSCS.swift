func maxSubArray(_ array: [Int]) -> Int {
    var currentSum = 0
    var result = Int.min
    for i in 0 ..< array.count {
        currentSum = max(array[i], array[i] + currentSum)
        result = max(result, currentSum)
    }
    return result
}

var array:[Int] = [-2, -3, 4, -1, -2, 1, 5, -3]
let max_sum = maxSubArray(array)
print("Maximum continous sum is \(max_sum)")

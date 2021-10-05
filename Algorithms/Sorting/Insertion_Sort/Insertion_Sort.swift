/*Swift Implementation for Insertion Sort Algorithm*/

//Binary Search to find location of where selected value should be inserted
func binarySearch(numbers: [Int], value: Int, max: Int, min: Int) -> Int
{
    var left = min
    var right = max
    
    while left <= right {
        
        let middle = left + (right-left)/2

        if (value == numbers[middle]){
            return middle
        }
        
        if (value < numbers[middle]) {
            right = middle - 1
        } else {
            left = middle+1
        }
        
    }

    return left
}

//Insertion Sort Function
func insertionSort(input_array: [Int]) -> [Int] {
    var sorted_array = input_array
    for i in 0..<sorted_array.count {
        let temp = sorted_array[i]
        let location = binarySearch(numbers: sorted_array, value: temp, max: i-1, min: 0)

        for j in stride(from: i-1, through: location, by: -1){
            sorted_array[j+1] = sorted_array[j]

        }
        sorted_array[location] = temp
    }
    
    return sorted_array
}

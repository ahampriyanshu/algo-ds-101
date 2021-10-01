package main

import "fmt"

func binarySearch(array []int, l int, r int, key int) int {
	for r-l > 1 {
		center := l + (r-l)/2
		if array[center] >= key {
			r = center
		} else {
			l = center
		}
	}

	return r
}

// LongestIncreasingSubsequence will returned a maximum increasing subsequence inside the input given
// with complexity O(N log N)
func LongestIncreasingSubsequence(input []int) int {
	if len(input) == 0 {
		return 0
	}

	length := 1
	array := make([]int, len(input))
	array[0] = input[0]

	for i := 1; i < len(array); i++ {
		if input[i] < array[0] {
			array[0] = input[i]
		} else if input[i] > array[length-1] {
			array[length] = input[i]
			length++
		} else {
			array[binarySearch(array, -1, length-1, input[i])] = input[i]
		}
	}

	return length
}

func main() {
	input := []int{1, 4, 3, 8, 12, 1, 9, 10, 3, 11, 0, 3}
	output := LongestIncreasingSubsequence(input)

	fmt.Println(output)
}

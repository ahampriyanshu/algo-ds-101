package main

import "fmt"

func main() {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	binarySearch := BinarySearch(arr, 5)
	fmt.Println(binarySearch)
}

func BinarySearch(arr []int, x int) string {
	var (
		start = 0
		end   = len(arr) - 1
		mid   = -1
	)

	for start != mid && end != mid {
		mid = start + (end-start)/2
		if arr[mid] == x {
			return fmt.Sprintf("Selection found at index %d", mid)
		}

		if arr[mid] > x {
			end -= 1
		} else {
			start = mid + 1
		}
	}
	return "Selection not found"
}

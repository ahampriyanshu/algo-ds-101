package main

import (
	"fmt"
)

func main() {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Print("Enter the number you want to search : ")
	var input int

	//Taking input from user
	fmt.Scanln(&input)

	binarySearch := BinarySearch(arr, input)
	fmt.Println(binarySearch)
}

func BinarySearch(arr []int, x int) string {
	var (
		start = 0
		end   = len(arr) - 1
		mid   = -1
	)
	//start looping for searching index
	for start != mid && end != mid {
		//set mid index
		mid = start + (end-start)/2
		//check if input equal at index mid then return
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

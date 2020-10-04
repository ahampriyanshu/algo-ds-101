package main

import (
	"fmt"
	"strconv"
)

func selectionSort(arr [100]int, n int) {
	for i := 0; i < n-1; i++ {
		var minIndex = i
		for j := i + 1; j < n; j++ {
			if arr[minIndex] > arr[j] {
				minIndex = j
			}
		}

		var temp = arr[minIndex]
		arr[minIndex] = arr[i]
		arr[i] = temp
	}
	fmt.Print("After Sorting: ")
	printArray(arr, n)
}

func printArray(arrs [100]int, n int) {
	for i := 0; i < n; i++ {
		fmt.Print(strconv.Itoa(arrs[i]) + " ")
	}
	fmt.Println("")
}

func main() {
	fmt.Print("How many number : ")
	var no = 0
	fmt.Scanln(&no)
	var arr [100]int
	fmt.Print("Enter array values : ")
	for i := 0; i < no; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Print("Before Sorting: ")
	printArray(arr, no)
	selectionSort(arr, no)
}

package main

import "fmt"

var arr = []int{1, 44, 37, 6, 54, 81, 21, 66}

func main() {
	fmt.Println("Before Sorting:", arr)
	stoogesort(arr)
	fmt.Println("After Stooge Sort: ", arr)
}

func stoogesort(arr []int) {
	end := len(arr) - 1
	if arr[end] < arr[0] {
		arr[0], arr[end] = arr[end], arr[0]
	}
	if end > 1 {
		t := len(arr) / 3
		stoogesort(arr[:len(arr)-t])
		stoogesort(arr[t:])
		stoogesort(arr[:len(arr)-t])
	}
}

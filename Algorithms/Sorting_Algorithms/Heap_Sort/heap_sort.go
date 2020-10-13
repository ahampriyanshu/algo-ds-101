package main

import "fmt"

func heapify(array []int, n, i int) {
	max := i
	l := 2*i + 1
	r := 2*i + 2

	if l < n && array[l] > array[max] {
		max = l
	}
	if r < n && array[r] > array[max] {
		max = r
	}

	if max != i {
		array[i], array[max] = array[max], array[i]
		heapify(array, n, max)
	}
}

// HeapSort will modify/sorted the original array
func HeapSort(array []int, n int) {
	for i := n/2 - 1; i >= 0; i-- {
		heapify(array, n, i)
	}
	for i := n - 1; i >= 0; i-- {
		array[0], array[i] = array[i], array[0]
		heapify(array, i, 0)
	}
}

func main() {
	array := []int{1, 4, 3, 8, 12, 1, 9, 10, 3, 11, 0, 3}
	HeapSort(array, len(array))

	for _, values := range array {
		fmt.Printf("%d ", values)
	}
	fmt.Println()
}

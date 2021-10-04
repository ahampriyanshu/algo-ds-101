package main

import "fmt"

func swap(num1 *int, num2 *int) {
	var val int
	val = *num1
	*num1 = *num2
	*num2 = val
}

func partition(elements []int, low int, high int) int {
	var pivot int
	pivot = elements[high]
	var i int
	i = low
	var j int
	for j = low; j < high; j++ {
		if elements[j] <= pivot {
			swap(&elements[i], &elements[j])
			i++
		}
	}
	swap(&elements[i], &elements[high])
	return i
}

func quickSort(elements []int, low int, high int) {
	if low < high {
		var part int
		part = partition(elements, low, high)
		quickSort(elements, low, part-1)
		quickSort(elements, part+1, high)
	}
}

func main() {
	var num int

	fmt.Print("Enter Number of Elements: ")
	fmt.Scan(&num)
	var array = make([]int, num)
	var i int

	for i = 0; i < num; i++ {
		fmt.Scan(&array[i])
	}

	fmt.Print("Elements: ", array, "\n")
	quickSort(array, 0, num-1)
	fmt.Print("Sorted Elements: ", array, "\n")
}

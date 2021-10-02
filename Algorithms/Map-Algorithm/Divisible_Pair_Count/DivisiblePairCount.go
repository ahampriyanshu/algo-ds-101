package main

import (
	"fmt"
)

func main() {
	count := 0
	fmt.Printf("Enter the total number of elements in the array :")
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Printf("Enter %dst element and press enter --> ", i+1)
		fmt.Scan(&arr[i])
	}

	for j := 0; j < n; j++ {
		for k := j + 1; k < n; k++ {
			if arr[j]%arr[k] == 0 || arr[k]%arr[j] == 0 {
				count++
			}
		}
	}

	fmt.Printf("The number of divisible pair in the array %d is %d\n", arr, count)
}

package main

import (
	"fmt"
)

func main() {
	//get number of levels in pyramid
	var levels int
	fmt.Println("Enter number of levels: ")
	fmt.Scan(&levels)

	//allocate pyramid[][]
	pyramid := make([][]int, levels)
	for i := range pyramid {
		pyramid[i] = make([]int, levels)
	}

	//get values for pyramid[][]
	fmt.Println("Please only enter positive integers")
	for r := 0; r <= levels-1; r++ {
		fmt.Printf("Enter %d items for level %d: ", r+1, r)
		for c := 0; c <= r; c++ {
			fmt.Scan(&pyramid[r][c])
		}
	}

	//print pyramid[][]
	fmt.Println("Here's the pyramid: ")
	for r := 0; r < levels; r++ {
		for c := 0; c <= r; c++ {
			fmt.Printf("%d ", pyramid[r][c])
		}
		fmt.Println("")
	}

	fmt.Printf("Minimum-Sum Descent for created pyramid (Tabular): %d", tabular(pyramid, levels-1))
	fmt.Println("")
}

/*
* Finds the minimum between two integers
 */
func minimum(a, b int) int {
	if a < b {
		return a
	}
	return b
}

/*
* Tabular Solution for created pyramid
 */
func tabular(arr [][]int, n int) int {
	for r := n; r >= 0; r-- {
		for c := 0; c <= r; c++ {
			if r != n {
				arr[r][c] = arr[r][c] + minimum(arr[r+1][c], arr[r+1][c+1])
			}
		}
	}
	return arr[0][0]
}

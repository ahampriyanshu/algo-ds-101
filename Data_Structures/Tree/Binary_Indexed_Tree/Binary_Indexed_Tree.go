package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// BITree is a binary indexed tree, great for getting the sum from index 1 to n
type BITree []int

// NewBITree builds a BITree from an array
func NewBITree(array []int) BITree {
	output := make(BITree, len(array)+1)
	for i := 1; i < len(output); i++ {
		output.Update(i, array[i-1])
	}
	return output
}

// Update can be used to manually add values in the BITree
func (b BITree) Update(i, val int) {
	for i < len(b) {
		b[i] += val
		// The line below makes i to move to the parent node
		i += i & (-i)
	}
}

// GetSum computes the sum from 1 to i in O(log n) time
func (b BITree) GetSum(i int) (sum int) {
	for i > 0 {
		sum += b[i]
		// The line below makes i to move to the parent node
		i -= i & (-i)
	}
	return
}

func main() {
	// Get the array
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Values separated by commas: ")
	text, _ := reader.ReadString('\n')
	text = strings.ReplaceAll(text, " ", "")

	// Convert the text array to an actual []int
	a := make([]int, strings.Count(text, ",")+1)
	var err error
	for i, val := range strings.Split(text[:len(text)-2], ",") {
		a[i], err = strconv.Atoi(val)
		if err != nil {
			panic(err)
		}
	}

	BIT := NewBITree(a)

	fmt.Println("Binary Indexed Tree array:")
	fmt.Println(BIT)

	fmt.Println("Press Ctrl+c to exit the loop...")
	for {
		index := 0
		fmt.Print("Get the sum from 1 to: ")
		fmt.Scan(&index)
		fmt.Println(BIT.GetSum(index))
	}
}

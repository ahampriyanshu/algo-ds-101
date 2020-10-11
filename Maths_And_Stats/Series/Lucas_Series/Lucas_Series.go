package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func printLucasSeries(size int) {
	// Print first two terms
	l1 := 2
	l2 := 1
	fmt.Print(l1, "  ", l2, "  ")
	for i := 2; i < size; i++ {
		l2 = l1 + l2
		l1 = l2 - l1
		fmt.Print(l2, "  ")
	}
	fmt.Println()
}
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the size of sequence (Number of values) for Lucas Series: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	inputNum, err := strconv.Atoi(input)
	if err != nil {
		fmt.Println("Input is not valid, Please enter a valid number", input, err)
		return
	}

	fmt.Printf("The first %v numbers in Lucas Series are \n", inputNum)
	printLucasSeries(inputNum)

}

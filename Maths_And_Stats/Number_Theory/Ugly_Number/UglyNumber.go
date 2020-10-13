// This file has the implementation to check whether a number is Ugly or not

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Check whether the function is ugly or not
func isUgly(num int) bool {
	for num >= 2 {
		if num%2 == 0 {
			num /= 2
		} else if num%3 == 0 {
			num /= 3
		} else if num%5 == 0 {
			num /= 5
		} else {
			return false
		}
	}
	return num == 1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter Number: ")
	input, _ := reader.ReadString('\n')
	fmt.Println(input)
	input = strings.TrimSuffix(input, "\n")
	inputNum, err := strconv.Atoi(input)
	if err != nil {
		fmt.Println("Input Number is not valid", input, err)
		return
	}

	if isUgly(inputNum) {
		fmt.Println("Input Number is Ugly Number")
	} else {
		fmt.Println("Input number is not Ugly")
	}
}

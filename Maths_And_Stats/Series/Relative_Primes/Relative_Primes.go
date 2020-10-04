package main

import (
	"fmt"
	"math/big"
)

func main() {
	num1 := big.NewInt(0)
	num2 := big.NewInt(0)
	greatest := big.NewInt(0)

	fmt.Scanln(num1)
	fmt.Scanln(num2)

	greatest.GCD(nil, nil, num1, num2)

	if greatest.Int64() == 1 {
		fmt.Println("The numbers are relatively prime")
	} else {
		fmt.Println("The numbers are not relatively prime")
	}
}

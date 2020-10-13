package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println("Enter the number for which square root is to be found :")
	var n string
	fmt.Scan(&n)
	var a float64 = 1
	var e float64 = 0.000001
	value, err := strconv.ParseFloat(n, 64)
	var temp float64 = value
	if err != nil {
		fmt.Printf("%s is not a valid number ", n)
		return
	}
	for temp-a > e {
		temp = (temp + a) / 2
		a = value / temp
	}
	fmt.Printf("Square rooot of %f is %.02f \n", value, temp)
}

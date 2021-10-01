package main

import (
	"fmt"
)

// Calculate the sum of N natural numbers
// using the arithmetic progression formula Sn = n/2 * (2*a + (n-1)d)
// Where:
// n: numbers of terms
// a: first term
// d: common difference
// for natural numbers the formula becomes: n/2 * (n+1)
func sumNNaturalNumbers(terms uint) uint {
	return (terms * (terms + 1))/2;
}

func main() {
	var numberOfTerms uint;
	var sum uint;

	// Get user input
	fmt.Printf("Enter the number of terms: ");
	_, err := fmt.Scanf("%d", &numberOfTerms);

	// make sure the input is/contains a number
	if err != nil {
		fmt.Println("Invalid input !");
		return;
	}

	// Calculate and display the sum
	sum = sumNNaturalNumbers(numberOfTerms);
	fmt.Println("The sum of the first", numberOfTerms, "natural number(s) is:", sum);

}
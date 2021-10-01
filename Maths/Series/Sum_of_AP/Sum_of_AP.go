/*
	This code takes input a, d & n and computes sum of Arithmetic Progression .
	Language : Golang
	Author : Pulkit Sapra
*/

package main

//Package fmt implements formatted I/O with functions analogous to C's printf and scanf. 
import (
	"fmt"
	)

// Function to compute AP : Return Type : float64
func sum_of_AP(a float64, d float64, n float64) float64{
	return ((n/2)*(2*a + (n-1)*d))
}

// Main Function
func main() {
	fmt.Println("Please enter initial element(a) ,common difference(d) and n")
	
	// Declaring variables and their types.
	var a,d,n float64

	// Taking input for a,d & n
	fmt.Scan(&a)
	fmt.Scan(&d)
	fmt.Scan(&n)

	//Function call
	ans := sum_of_AP(a,d,n)
	
	fmt.Println(ans)
	
}

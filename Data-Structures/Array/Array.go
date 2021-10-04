package main

import "fmt"

func main() {
	var size int
   	 fmt.Printf("Enter size of your array: ")
   	// takes size from user
    	fmt.Scanln(&size)
	// declaration of the array
   	 var elements = make([]int, size)
	 
	for i := 0; i < size; i++ {
    	// take input elements from the user	
		fmt.Scanln(&elements[i])
	}
  	// print out the elements array
	fmt.Println(elements)
}

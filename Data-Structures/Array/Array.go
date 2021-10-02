package main

import "fmt"

func main() {
 	
  // declaration of the array
	var elements [3]string
	 
	for i := 0; i < 3; i++ {
    // take input elements from the user	
		fmt.Scanln(&elements[i])
	}
  // print out the elements array
	fmt.Println(elements)
}

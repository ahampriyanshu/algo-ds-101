package main
import "fmt"

/*
Takes in an int array to search and an int value for searching.
Returns true if value is found and false otherwise.
LinearSearch runs in O(n) time.
*/ 
func LinearSearch(array []int, target int) bool {
    for _, item := range array {
        if item == target {
            return true
        }
    }
    return false
} 

// main function tests the LinearSearch function  
func main() {
    items := []int{82,78,46,28,79,28,68,321,145, 1089}
    fmt.Println(LinearSearch(items,28))
}

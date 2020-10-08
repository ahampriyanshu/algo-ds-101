package main
import "fmt"
 
func fact(n int) int {
   if n == 0 {
      return 1
   }
   return n * fact(n-1)
}
 
func main() {
   for i := 1; i <= 10; i++ {
      fmt.Printf("%2d: %d \n", i, fact(i))
   }
}
 

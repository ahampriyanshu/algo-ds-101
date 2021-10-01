package main

import "fmt"

func Fibonacci(n uint) uint64 {
  if n <= 1 {
    return uint64(n)
  }

  var n2, n1 uint64 = 0, 1

  for i := uint(2); i < n; i++ {
    n2, n1 = n1, n1+n2
  }

  return n2 + n1
}

func main() {
	for i := uint(0); i < 10; i++ {
		fmt.Println(Fibonacci(i))
	}
}
package main

import "fmt"

func checkPrime(n int) bool {
	if n > 1 {
		if n == 2 {
			return true
		}

		for i := 2; i < n; i++ {
			if n % i == 0 {
				return false
			}
		}
	} else {
		return false
	}
	return true
}

func generateSieve(n int) []int {
	var sieve []int
	for i := 1; i < n; i++ {
		if checkPrime(i) {
			sieve = append(sieve, i)
		}
	}
	return sieve
}

func main() {
	fmt.Println(generateSieve(500))
}
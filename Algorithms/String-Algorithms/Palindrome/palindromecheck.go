package main

import (
   "fmt"
   "strings"
)

func Reverse(s string) (result string) {
   for _, v := range s {
      result = string(v) + result
   }
   return
}

func isPalindrome(str string) interface{} {
   if str == Reverse(str) {
      return true
   }
   return false
}

func main() {
   var str string
   fmt.Print("Enter a string: ")
   fmt.Scan(&str)
   if isPalindrome(strings.ToUpper(str)) == true {
      fmt.Print(str, " is a palindrome.")
   } else {
      fmt.Print(str, " is not a palindrome.")
   }
}

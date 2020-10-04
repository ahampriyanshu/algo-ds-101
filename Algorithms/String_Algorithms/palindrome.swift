import Foundation

func palindrome(string: String)-> Bool{
    let char = Array(string)
    for i in 0..<char.count / 2 {
        if char[i] != char[char.count - 1 - i] {
            return false
        }
    }
    return true
}

print("Program for checking if a string is palindrome or not")
print("Please enter the string")
let value = readLine()
if let value = value {
  let isPalindrome = palindrome(string: value)
  isPalindrome ? print("\(value) is a palindrome") : print("\(value) is not a palindrome")
}

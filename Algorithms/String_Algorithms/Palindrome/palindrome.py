# Palindrome
# Python

def palindrome(rawString):
    return rawString[::-1] == rawString

if __name__ == "__main__":
    rawString = input("Enter a string: ")
    if palindrome(rawString.lower()) == True:
        print("It is a Palindrome!")
    else:
        print("It is not a Palindrome!")

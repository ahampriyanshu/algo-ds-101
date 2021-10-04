'''
The factorial of a positive integer n, detoned by n! is the product of all positive integers less than or equal to n.
Examples: 
1) The factorial of 3 is 6, because: 3*2*1 = 6
2) The factorial of 5 is 120, because: 5*4*3*2 = 120

The value of 0! is 1

The following method shows how recursion can be used to calculate the factorial of any given number

'''

def factorial(n):
    if(n == 1 or n == 0):
        return 1
    else:
        return n * factorial(n-1)

#The following code is used to test the code with an input from the user
while True:
    try:
        user_input = int(input("Please enter the number to be computed: "))
        if(user_input < 0):
            print("The number cannot be negative!")
            continue
        else:
            print(factorial(user_input))
    except ValueError:
        print("The number should be a integer!")
        continue
    else:
        break
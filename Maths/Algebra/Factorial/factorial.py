# recursive function to calculate factorial of a number
def fact(num):

    # if the number is greater than 0
    # make a recursive call to the function
    if num > 0:
        factorial = num * fact(num-1)
    
    else:
        factorial = 1
    
    # return the factorial
    return factorial

# taking an integer input
n = int(input("Enter the number: "))

# print the factorial of the number
print(fact(n))
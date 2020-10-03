#GCD using recursion

# Recursive function to return gcd of a and b
def gcd(a,b):
     
    # Everything divides 0 
    if (a == 0):
        return b
    if (b == 0):
        return a
 
    # base case
    if (a == b):
        return a  # or return b
 
    # greater one
    if (a > b):
        return gcd(a-b, b) # a is greater
    return gcd(a, b-a) # b is greater

 
# Driver program to test above function
a = int(input("Enter first no: "))
b = int(input("Enter second no: "))
if(gcd(a, b)):
    print('GCD of', a, 'and', b, 'is', gcd(a, b))

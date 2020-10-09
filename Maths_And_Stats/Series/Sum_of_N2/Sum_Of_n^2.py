'''Python3 Program to find sum of square
 of first n natural numbers
Return the sum of square of first n natural numbers.
'''
def squaresum(n) : 
    return (n * (n + 1) * (2 * n + 1)) // 6
'''
Avoiding early overflow:
For large n,it would overflow.
We can avoid overflow using  n*(n+1) must be divisible by 2.

return (n * (n + 1) / 2) * (2 * n + 1) / 3 
use above code while large numbers
'''

# Driven Program 
n =int (input("Enter the number:::"))
print(squaresum(n)) 
  
#This code is contributed by Himik Nainwal
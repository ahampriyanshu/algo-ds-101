# -*- coding: utf-8 -*-
"""
@ Author: Sandip Dutta
--------------------------------------------------------------
Code for Modular Exponentiation
Modular Exponentiation is an algorithm for calculating
(a^b) % m fast.

a^b is useful for us but it's value may be large 
and it might overflow. So we calculate (a^b) % m.

The idea of modular exponentiation can be shown with the 
help of the following ideas
    1.  (a * b) % (m) = (a %(m) * b %(m)) %(m)
    2.  a ^ b   = (a ^ (b/2) * a ^ (b/2)) when b is even
                = (a * a ^ (b-1)) when b is odd

These two ideas gives us the recursive version of the algorithm
we will implement.

>   Runtime - O(log (b))
---------------------------------------------------------------
NOTE : In python, pow() function implements this idea
---------------------------------------------------------------
"""

def modularExp(a, b, m):
    '''
    Performs modular Exponentiation, that is a^b % m fast.
    @ Args:
        a - (int) mantissa / base
        b - (int) exponent
        m - (int) number with respect to which modulus is calculated
    @ Return:
        y - (int) the value of (a ^ b) % m
    '''
    # Base Case - a == 0, return 0; b == 0, return 1
    if a == 0: return 0
    if b == 0: return 1

    y = 0 # Final Value

    # If b is odd, then b & 1(bitwise AND) == 1, else 0
    # We do not use b % 2 here as bitwise operations might be 
    # faster for larger b value

    # b is odd
    if b & 1:
        y = a % m    # Break as per step 1 above
        y = (y * modularExp(a, b - 1, m) % m) % m    
        # Break as per step 2 above
    
    else:
        y = modularExp(a, b // 2, m)
        y = (y * y) % m
        # Break as per step 2 above

    # this is to ensure that y is not negative
    return ((y + m) % m)

#------------------------------------------------------

if __name__ == "__main__":
    a, b, m = list(map(int, input("Enter a, b, m: ").split()))
    print(modularExp(a, b, m))
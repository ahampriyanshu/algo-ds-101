"""A geometric progression, also known as a geometric sequence, 
is a sequence of numbers where each term after the first is found by 
multiplying the previous one by a fixed, non-zero number called the 
common ratio.
a, a*r, a*r*r,.... forms a GP.
where a is the first element and r is the common ratio.
Sum of GP is given by a*(r^n - 1)/(r - 1) where n is the number of terms."""

def sumOfGP(a,r,n):
    return a*(pow(r,n)-1)/(r-1)
    
a = 2
r = 2
n = 15
print(sumOfGP(a,r,n))
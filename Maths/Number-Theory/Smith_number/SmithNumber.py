# ---------------------------------PROBLEM STATEMENT--------------------------------
# Given a number n, the task is to find out whether this number is smith number or not. 
# Smith Number is a composite number whose sum of digits is equal to the 
# sum of digits in its prime factorization.

# Python Code to identify Smith Number -

def factors(n):
    f, fs = 3, []
    while n % 2 == 0:    
        fs.append(2)
        n /= 2
    while f * f <= n:
        while n % f == 0:
            fs.append(f)
            n /= f
        f += 2
    if n > 1: fs.append(n)
    return fs

# Finding sum of digits of prime factor of the given number
 
def getIntLetterCount(n):
    return sum([int(l) for l in list(str(n))])
 
def isSmithNumber(n):
    return sum([getIntLetterCount(f) for f in factors(n)]) == getIntLetterCount(n)

# Driver Code :    
 
if __name__ == '__main__':

    # Input the number to be checked whether Smith number or not 
    n = input()
 
    if isSmithNumber(n):
        print ("It is Smith Number")
    else:
        print ("It is not a Smith Number")



# The first few Smith Numbers are as follows : 4 22 27 58 85 94 121 166 202 265 274 319 346 355...
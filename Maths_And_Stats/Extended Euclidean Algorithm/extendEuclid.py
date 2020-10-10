# Python program to demonstrate working of extended
# Euclidean Algorithm

# function for extended Euclidean Algorithm
def gcdExtended(a, b):
    # Base Case
    if a == 0:
        return b, 0, 1

    gcd, x1, y1 = gcdExtended(b % a, a)

    # Update x and y using results of recursive
    # call
    x = y1 - (b // a) * x1
    y = x1

    return gcd, x, y


# Driver code
first_number, second_number = 35, 15
gcd, x, y = gcdExtended(first_number, second_number)
print("gcd(", first_number, ",", second_number, ") = ", gcd)
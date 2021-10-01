# function
def euclid_gcd(a, b):
    if b == 0:
        print(a)
        return a
    c = a%b
    euclid_gcd(b, c)


# input 2 numbers with a space between them
a, b = map(int, input().split())
euclid_gcd(min(a, b),max(a,b))

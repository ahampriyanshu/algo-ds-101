# Uses python3
import sys

def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l
    return a*b

# SOLUTION
# Using a formula that turn the lcm problem into the gcd problem which is
# already solved: the formula is the absolut value of the product of a and b
# divided by the gcd of a and b
def lcm_fast(a, b):
	return int(abs(a*b)/euclid_gcd(a, b))

def euclid_gcd(a, b):
	if b == 0:
		return a
	return euclid_gcd(b, a%b)

if __name__ == '__main__':
    input = sys.stdin.read()
    a, b = map(int, input.split())
    print(lcm_fast(a, b))

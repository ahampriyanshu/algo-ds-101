#Function checks if input is an ugly number or not
import sys

#Function from: w3resource.com
def is_ugly_number(num):
    if num == 0:
        return False
    for i in [2, 3, 5]: #2,3 and 5 must be the only prime factors of the ugly number
        while num % i == 0:
            num /= i
    return num == 1

print(is_ugly_number(int(sys.argv[1])))

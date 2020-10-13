def gcd(num1, num2):

    if num2 == 0:
        return num1
    
    return gcd(num2, num1 % num2)

def is_relative_prime(num1, num2):

    if gcd(num1, num2) == 1:
        return True
    
    return False


number = int(input("Enter a number: "))

print("Numbers that are relatively prime to ", number," are:")

for i in range(2, number):

    if is_relative_prime(number, i):
        print(i)

"""
Example:
Enter a number: 9
Numbers that are relatively prime to 9 are:
2
4
5
7
8
"""

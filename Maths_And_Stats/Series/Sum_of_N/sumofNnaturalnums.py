#  Sum of n natural Number in python3 ..

try:
    n=int(input("Enter the Nth term upto which you want to calculate the sum: "))
    a=1
    d=1
    ans = (n/2)*(2*a + (n-1)*d)
    print(ans)

except ValueError:
    print("Please enter a valid integer with base 10.")


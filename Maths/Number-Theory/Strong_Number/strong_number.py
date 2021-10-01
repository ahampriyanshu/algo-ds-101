n= int(input("Enter the number : "))
sum = 0
temp = n
while (n):
    i = 1
    fact = 1
    rem = int(n % 10)

while(i <= rem):
    fact = fact * i
    i = i + 1
    sum = sum + fact
    n = int(n / 10)

if(sum == temp):
    print(temp,end = "")
    print(" is a strong number")
else:
    print(temp,end = "") 
    print(" is not a strong number")


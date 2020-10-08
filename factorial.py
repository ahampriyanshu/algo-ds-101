def factorial(n):
    if (n<0): 
        return ("ERROR - Negatives can't have factorials !!")
    if (n==0 or n==1):
        return 1
    while (n>1):
        return n*factorial(n-1)

number = int(input("Enter number"))
print (factorial(number))

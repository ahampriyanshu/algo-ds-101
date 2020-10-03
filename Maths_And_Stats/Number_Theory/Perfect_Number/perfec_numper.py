def isPerfect( n ):  
    sum,i = 1,2
    while i * i <= n: 
        if n % i == 0: 
            sum = sum + i + n/i 
        i += 1  
    return (True if sum == n and n!=1 else False) 
  
n = int(input("Enter a number to check if it's Perfect or not : "))

if isPerfect(n):
    print(n, "is aPerfect Number")
else:
    print(n, "is not a Perfect Number")
    
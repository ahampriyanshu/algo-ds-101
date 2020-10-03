def check_armstrong(num):
    sums = 0
    p = num
    while num != 0:
        digit = num % 10
        sums += pow(digit, 3)
        num //= 10
    if sums == p:
        return "Yes"
    else:
        return "No"


number = int(input("Enter a number: "))
result = check_armstrong(number)
print(result)
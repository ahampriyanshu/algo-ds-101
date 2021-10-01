

numlist = []
num1 = int(input("number: \n"))

for i in range(1, num1 - 1):
    y = num1%i
    if(y == 0):
        numlist.append(i)
x = 0
for i in range(len(numlist)):
    x = x + numlist[i]

if(x == num1):
    print(num1, " is a perfect number!")

else:
    print(num1, " is not a perfect number")

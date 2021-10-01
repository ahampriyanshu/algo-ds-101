
#Taking Input
print("Enter the size of list : ")
size = int(input())

print("Enter the list elements: ")
arr = list(map(int,input().split()))

total_sum = sum(arr)

mean = total_sum /size

print("Mean is : {}".format(mean))

'''
    Sample Input :
        enter the size of list: 5
        Enter the list elements : 10 30 20 40 50
    
    Sample Output:
        Mean is 30.0
'''
#method 1 using brute force approach
 
 
def Checksumr(arr, l, s):
    global count
    count = 0  
    for i in range(0, l):
        for j in range(i + 1, l):
            if arr[i] + arr[j] == s:
                print(arr[i],arr[j])
                count += 1
    if count==0:
        print("no such pair found")
    else:
        print(count,"pairs found as listed")
print("enter numbers in one line with spaces")
arr=list(map(int,input().split()))
l = len(arr)
print("enter sum")
s=int(input())
Checksumr(arr, l, s)

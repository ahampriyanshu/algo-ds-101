def sortInWave(arr_demo, n):
    arr_demo.sort()
    for i in range(0,n-1,2):
        arr_demo[i], arr_demo[i+1] = arr_demo[i+1], arr_demo[i]

    return arr_demo

arr = []
print("Please Enter no of elements in array")
n = int(input())
print("Please Enter elements of the array")
for i in range(n):
    sample = int(input())
    arr.append(sample)

sortInWave(arr, len(arr)) 

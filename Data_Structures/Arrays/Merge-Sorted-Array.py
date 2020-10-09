
from heapq import merge 
def mergeK(arr, k):     
    l = arr[0] 
    for i in range(k-1): 
        l = list(merge(l, arr[i + 1])) 
    return l 
  
def printArray(arr): 
    print(*arr) 
  

arr =[[3, 4, 16 ],  
    [ 5, 9 ],  
    [22, 54, 94, 200 ]] 
k = 3

out = mergeK(arr, k) 
printArray(out) 

import bisect

def binsertion_sort(arr):
    '''
    Author: Kinshuk Dua (@kinshukdua)
    Python program to perform binary insertion sort
    Comparison complexity O(nlogn)
    Sorting complexity O(n^2)
    '''
    for i in range(1,len(arr)):
        bisect.insort(arr, arr.pop(i), 0, i)
    return

#testing
arr = [5,4,3,2,1]
binsertion_sort(arr)
print(arr)
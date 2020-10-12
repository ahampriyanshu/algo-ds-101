# This is the Python version of Quick Sort
# Code is contributed by: Italo Vinicius.
# 
# Quick sort is an Sorting Algorithm which takes compelxity: O(n log n)

# This function takes last element as pivot, places 
# the pivot element at its correct position in sorted 
# array, and places all smaller (smaller than pivot) 
# to left of pivot and all greater elements to right 
# of pivot 

def partition(arr,low,high): 
    i = ( low-1 )         # index of smaller element 
    pivot = arr[high]     # pivot 

    for j in range(low , high): 

        # If current element is smaller than the pivot 
        if   arr[j] < pivot: 

            # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 

    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return ( i+1 ) 

# Function to do Quick sort 
def quickSort(arr,low,high): 
    if low < high: 

        # pi is partitioning index, arr[p] is now 
        # at right place 
        pi = partition(arr,low,high) 

        # Separately sort elements before 
        # partition and after partition 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 

if __name__ == "__main__":
    arr = list(map(int,input().split()))
    quickSort(arr,0,len(arr)-1)

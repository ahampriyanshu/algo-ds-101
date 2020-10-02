# This is the Python version of Insertion Sort
# Code is contributed by: Italo Vinicius.
# 
# Insertion sort is an Sorting Algorithm which takes compelxity: O(n²)

# Function to do insertion sort 
def insertionSort(arr): 
  
    # Traverse through 1 to len(arr) 
    for i in range(1, len(arr)): 
  
        key = arr[i] 
  
        # Move elements of arr[0..i-1], that are 
        # greater than key, to one position ahead 
        # of their current position 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 

if __name__ == "__main__":
    arr = list(map(int,input().split()))
    insertionSort(arr)
    
    print(' '.join(str(x) for x in arr))
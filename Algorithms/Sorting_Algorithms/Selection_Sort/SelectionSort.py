# This is the Python version of Selection Sort
# Code is contributed by: Italo Vinicius.
# 
# Selection sort is an Sorting Algorithm which takes compelxity: O(n²)

# Function to do selection sort 
def selectionSort(arr): 
  
    # Traverse through all array elements 
    for i in range(len(arr)): 
        
        # Find the minimum element in remaining  
        # unsorted array 
        min_idx = i 
        for j in range(i+1, len(arr)): 
            if arr[min_idx] > arr[j]: 
                min_idx = j 
                
        # Swap the found minimum element with  
        # the first element         
        arr[i], arr[min_idx] = arr[min_idx], arr[i]  

if __name__ == "__main__":
    arr = list(map(int,input().split()))
    selectionSort(arr)
    
    print(' '.join(str(x) for x in arr))
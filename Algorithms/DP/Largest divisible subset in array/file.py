# Python 3 program to find largest divisible subset in a given array 
  
# Prints largest divisible subset 
def findLargest(arr, n): 
      
    # We first sort the array so that all divisors of a number are before it. 
    arr.sort(reverse = False) 
  
    # To store count of divisors of all elements 
    divCount = [1 for i in range(n)] 
  
    # To store previous divisor in result 
    prev = [-1 for i in range(n)] 
  
    # To store index of largest element in maximum size subset 
    max_ind = 0
  
    # In i'th iteration, we find length of chain ending with arr[i] 
    for i in range(1,n): 
        # Consider every smaller element as previous element. 
        for j in range(i): 
            if (arr[i] % arr[j] == 0): 
                if (divCount[i] < divCount[j] + 1): 
                    divCount[i] = divCount[j]+1
                    prev[i] = j 
  
        # Update last index of largest subset if size of current subset is more. 
        if (divCount[max_ind] < divCount[i]): 
            max_ind = i 
  
    # Print result 
    k = max_ind 
    while (k >= 0): 
        print(arr[k],end = " ") 
        k = prev[k] 
  
# Driven code 
if __name__ == '__main__': 
    arr = [1, 2, 17, 4] 
    n = len(arr) 
    findLargest(arr, n) 

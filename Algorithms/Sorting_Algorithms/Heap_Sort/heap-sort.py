'''
Input format: contents of the array
Output format: Sorted Array
Time Complexity: O(NlogN)
Space Complexity: O(N)

**Sample Input Output**

Enter the elements of the array: 2 3 1 4 5 6 8 9
Sorted array is:  1 2 3 4 5 6 8 9

'''

# Python program for implementation of Heap Sort 

# Maintaining max heap
def heapify(arr, n, index): 
	largest = index # Initialize largest as root 
	left = 2 * index + 1	 # left = 2 * index + 1 
	right = 2 * index + 2	 # right = 2 * index + 2 

	# See if left child of root exists and is 
	# greater than root 
	if left < n and arr[index] < arr[left]: 
		largest = left 

	# See if right child of root exists and is 
	# greater than root 
	if right < n and arr[largest] < arr[right]: 
		largest = right 

	# Change root, if needed 
	if largest != index: 
		arr[index],arr[largest] = arr[largest],arr[index] # swap 

		# recursively build max heap
		heapify(arr, n, largest) 

# The main function to sort an array of given size 
def heapSort(arr): 
	n = len(arr) 

	# Build a maxheap. 
	# Since last parent will be at ((n//2)-1) we can start at that location. 
	for i in range(n // 2 - 1, -1, -1): 
		heapify(arr, n, i) 

	# One by one extract elements 
	for i in range(n-1, 0, -1): 
		arr[i], arr[0] = arr[0], arr[i] # swap 
		heapify(arr, i, 0) 

# Driver code to test above 
arr = list(map(int,input("Enter the elements of the array: ").split()))
heapSort(arr) 
n = len(arr) 
print ("Sorted array is: ",end=" ") 
print(*arr)


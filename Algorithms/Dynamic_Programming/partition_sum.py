def findPartition(arr, n): 
	sum = 0
	i, j = 0, 0
	
	# calculate sum of all elements 
	for i in range(n): 
		sum += arr[i] 
	
	if sum % 2 != 0: 
		return false 
	
	part = [[ True for i in range(n + 1)] 
				for j in range(sum // 2 + 1)] 
	
	# initialize top row as true 
	for i in range(0, n + 1): 
		part[0][i] = True

	for i in range(1, sum // 2 + 1): 
		part[i][0] = False
	for i in range(1, sum // 2 + 1): 
		for j in range(1, n + 1): 
			part[i][j] = part[i][j - 1] 
			if i >= arr[j - 1]: 
				part[i][j] = (part[i][j] or
							part[i - arr[j - 1]][j - 1]) 
		
	return part[sum // 2][n] 
	
# Driver Code 
arr = [3, 1, 1, 2, 2, 1] 
n = len(arr) 
if findPartition(arr, n) == True: 
	print("Can be divided into two", 
			"subsets of equal sum") 
else: 
	print("Can not be divided into ", 
		"two subsets of equal sum") 

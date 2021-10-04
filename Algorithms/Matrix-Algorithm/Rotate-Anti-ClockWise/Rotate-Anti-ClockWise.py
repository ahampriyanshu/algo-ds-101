// Code contributed by Vatsalya Gupta
# Python 3 program for left rotation of matrix by 90 degree without using extra space

R = 4
C = 4

# After transpose we swap elements of column one by one for finding left rotation of matrix by 90 degree

def reverseColumns(arr):
	for i in range(C):
		j = 0
		k = C-1
		while j < k:
			t = arr[j][i]
			arr[j][i] = arr[k][i]
			arr[k][i] = t
			j += 1
			k -= 1

# Function for do transpose of matrix

def transpose(arr):
	for i in range(R):
		for j in range(i, C):
			t = arr[i][j]
			arr[i][j] = arr[j][i]
			arr[j][i] = t

# Function for print matrix

def printMatrix(arr):
	for i in range(R):
		for j in range(C):
			print(str(arr[i][j]), end=" ")
		print()

# Function to anticlockwise rotate matrix by 90 degree

def rotate90(arr):
	transpose(arr)
	reverseColumns(arr)


# Driven code
arr = [[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9, 10, 11, 12],
	[13, 14, 15, 16]
	]
rotate90(arr)
printMatrix(arr)

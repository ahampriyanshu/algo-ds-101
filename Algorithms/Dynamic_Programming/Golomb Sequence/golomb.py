# Golomb sequence 
def findGolomb(n): 

	if (n == 1): 
		return 1

	return 1 + findGolomb(n - findGolomb(findGolomb(n - 1))) 
 
def printGolomb(n): 

	for i in range(1, n + 1): 
		print(findGolomb(i), end=" ") 

n = 19
printGolomb(n) 

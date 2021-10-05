import math 

# Calculating the sum 
# of proper divisors 
def sumOfDiv(x): 
	
	# 1 is a proper divisor 
	sum = 1; 
	for i in range(2,int(math.sqrt(x))): 
		if x % i==0: 
			sum += i 
			
			# To handle perfect squares 
			if i != x/i: 
				sum += x/i 
	return int(sum); 


def isAmbicle(a, b): 
	return (sumOfDiv(a) == b and
			sumOfDiv(b) == a) 


def countPairs(arr,n): 
	s = set() 
	count = 0
	for i in range(n): 
		s.add(arr[i]) 
	
	for i in range(n):	 
		if sumOfDiv(arr[i]) in s: 
			
			# It's sum of proper divisors 
			sum = sumOfDiv(arr[i]) 
			if isAmbicle(arr[i], sum): 
				count += 1		
	

	return int(count/2); 
	
# Driver Code 
arr1 = [220, 284, 1184, 
		1210, 2, 5] 
n1 = len(arr1) 
print(countPairs(arr1, n1)) 



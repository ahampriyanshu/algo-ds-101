# Python program for finding median 

# list of elements to calculate median 
data = [7, 2, 3, 6, 7] 

# length of the list
length = len(data) 

# Sort list
data.sort() 

# check if the length of list is odd or even
if length % 2 == 0: 
	median1 = data[length//2] 
	median2 = data[length//2 - 1] 
	median = (median1 + median2)/2
else: 
	median = data[length//2] 
	
# Print Median
print("Median is: " + str(median)) 
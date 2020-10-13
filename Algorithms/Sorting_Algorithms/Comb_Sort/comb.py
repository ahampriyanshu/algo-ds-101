def getNextGap(gap):  
	gap = (gap * 10)/13
	if gap < 1: 
		return 1
	return gap 

def combSort(array_to_sort): 
	gap = n = len(array_to_sort) 
	to_swap = 1

	while gap !=1 or to_swap == 1: 
		gap = getNextGap(gap) 
		to_swap = 0
		for i in range(0, n-gap): 
			if array_to_sort[i] > array_to_sort[i + gap]: 
				array_to_sort[i], array_to_sort[i + gap] = array_to_sort[i + gap], array_to_sort[i] 
				to_swap = 1


array_to_sort = [2,3,24,45,2,11,5,42,24] 
combSort(array_to_sort) 

print ("Array after applying comb sort") 
for i in range(len(array_to_sort)): 
	print (array_to_sort[i]), 

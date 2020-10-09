from heapq import heapify, heappush, heappop 

# Creating empty heap 
heap = [] 
heapify(heap) 

# Adding items to the heap using heappush function 
heappush(heap, 10) 
heappush(heap, 20) 
heappush(heap, 50) 
heappush(heap, 400) 

# printing the value of minimum element 
print("Head value of heap : "+str(heap[0])) 

# printing the elements of the heap 
print("The heap elements : ") 
for i in heap: 
	print(i, end = ' ') 
print("\n") 

element = heappop(heap) 

# printing the elements of the heap 
print("The heap elements : ") 
for i in heap: 
	print(i, end = ' ') 

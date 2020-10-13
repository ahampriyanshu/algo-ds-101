class MinHeap:
    def __init__(self, array):
        self.heap = self.buildHeap(array)

	# O(N)T | O(1)S
    def buildHeap(self, array):
        firstParentIdx = (len(array)-2) // 2
		for currIdx in reversed(range(firstParentIdx+1)):
			self.siftDown(currIdx, len(array)-1, array)
		return array

	# O(logN)T | O(1)S
    def siftDown(self, currIdx, endIdx, heap):
		childOneIdx = currIdx*2 + 1
		while childOneIdx <= endIdx:
			childTwoIdx = currIdx*2 + 2 if currIdx*2 + 2 <= endIdx else -1
			if childTwoIdx != -1 and heap[childTwoIdx] < heap[childOneIdx]:
				idxToSwap = childTwoIdx
			else:
				idxToSwap = childOneIdx
			if heap[idxToSwap] < heap[currIdx]:
				self.swap(currIdx, idxToSwap, heap)
				currIdx = idxToSwap
				childOneIdx = currIdx*2+1
			else:
				return

	# O(logN)T | O(1)S
    def siftUp(self, currIdx, heap):
		parentIdx = (currIdx-1) // 2
		while currIdx > 0 and heap[currIdx] < heap[parentIdx]:
			self.swap(currIdx, parentIdx, heap)
			currIdx = parentIdx
			parentIdx = (currIdx-1) // 2

	# O(1)T | O(1)S
    def peek(self):
        # Write your code here.
    	return self.heap[0]

	# O(logN)T  | O(1)S
    def remove(self):
		self.swap(0, len(self.heap)-1, self.heap)
        valueToRemove = self.heap.pop()	
		self.siftDown(0,len(self.heap)-1,self.heap)
		return valueToRemove

	# O(logN)T | O(1)S
    def insert(self, value):
		self.heap.append(value)
		self.siftUp(len(self.heap)-1,self.heap)
		
	def swap(self,i,j,heap):
		heap[i],heap[j]=heap[j],heap[i]

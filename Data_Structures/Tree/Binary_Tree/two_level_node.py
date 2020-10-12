class Node: 
	# Constructor tor create a new node 
	def __init__(self, key): 
		self.key = key 
		self.left = None
		self.right = None
	


def printLevels(root, low, high): 
	Q = [] 
	
	marker = Node(11114) # Marker node to indicate end of level 
	
	level = 1 # Initialize level number 

	# Enqueue the only first level node and marker node for 
	# end of level 
	Q.append(root) 
	Q.append(marker) 
	
	#print Q 
	# Simple level order traversal loop 
	while(len(Q) >0): 
		# Remove the front item from queue 
		n = Q[0] 
		Q.pop(0) 
		#print Q 
		# Check if end of level is reached 
		if n == marker: 
			# print a new line and increment level number 
			print
			level += 1
		
			# Check if marker node was last node in queue 
			# or level nubmer is beyond the given upper limit 
			if len(Q) == 0 or level > high: 
				break
			
			# Enqueue the marker for end of next level 
			Q.append(marker) 
			
			# If this is marker, then we don't need print it 
			# and enqueue its children 
			continue
		if level >= low: 
				print n.key, 
			
		# Enqueue children of non-marker node 
		if n.left is not None: 
			Q.append(n.left) 
			Q.append(n.right) 

# Driver program to test the above function 
root = Node(20) 
root.left = Node(8) 
root.right = Node(22) 
root.left.left = Node(4) 
root.left.right = Node(12) 
root.left.right.left = Node(10) 
root.left.right.right = Node(14) 

print "Level Order Traversal between given two levels is", 
printLevels(root,2,3) 



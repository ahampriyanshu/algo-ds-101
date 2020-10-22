					 
class newNode: 

	# Construct to create a new node 
	def __init__(self, key): 
		self.data = key 
		self.left = None
		self.right = None

def checkDupUtil( root, s) : 

	# If tree is empty, there are no 
	# duplicates. 
	if (root == None) : 
		return False

	# If current node's data is already present. 
	if root.data in s: 
		return True

	# Insert current node 
	s.add(root.data) 
	
	# Recursively check in left and right 
	# subtrees. 
	return checkDupUtil(root.left, s) or checkDupUtil(root.right, s) 


# To check if tree has duplicates 
def checkDup( root) : 

	s=set() 
	return checkDupUtil(root, s) 


# Driver Code 
if __name__ == '__main__': 
	root = newNode(10) 
	root.left = newNode(5) 
	root.right = newNode(20) 
	root.left.left = newNode(20) 
	if (checkDup(root)): 
		print("Yes") 
	else: 
		print("No") 


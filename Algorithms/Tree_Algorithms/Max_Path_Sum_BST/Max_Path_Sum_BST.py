#O(N) T | O(1) S

def maxPathSum(tree):
 _, maxSum = findMaxSum(tree)
 return maxSum
 
def findMaxSum(tree):
	if tree is None:
		return(0, float("-inf"))
		
	leftSumAsBranch, leftMaxPathSum = findMaxSum(tree.left)
	rightSumAsBranch, rightMaxPathSum = findMaxSum(tree.right)
	maxChildSumAsBranch = max(leftSumAsBranch,rightSumAsBranch)
	
	value = tree.value
	maxSumAsBranch = max(maxChildSumAsBranch+value,value)
	maxSumUsingRootNode = max(maxSumAsBranch, leftSumAsBranch + value + rightSumAsBranch)
	runningMaxPathSum = max(leftMaxPathSum, rightMaxPathSum, maxSumUsingRootNode)
	
	return (maxSumAsBranch,runningMaxPathSum)
# Leetcode Problem Link:
# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def lowestCommonAncestor(root,val1,val2):
    if root == None or root.val == val1 or root.val == val2:
        return root
    left = lowestCommonAncestor(root.left,val1,val2)
    right = lowestCommonAncestor(root.right,val1,val2)
    if left and right:
        return root
    return left if left is not None else right
    

#Creating a Binary Tree
root = TreeNode(1) 
root.left = TreeNode(2) 
root.right = TreeNode(3) 
root.left.left = TreeNode(4) 
root.left.right = TreeNode(5) 
root.right.left = TreeNode(6) 
root.right.right = TreeNode(7) 

ancestor = lowestCommonAncestor(root,4,5)
print(ancestor.val)


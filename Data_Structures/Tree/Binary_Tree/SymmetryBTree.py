# Node structure 
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        """"
        Creates a new tree node
        :param val: Value of the node
        :param left: Node on the left
        :param right: Node on the right
        """
        self.val = val
        self.left = left
        self.right = right
    

def isMirror(root1, root2):
    """"
    Returns True if trees with roots as root1 and root 2  are mirror 
    :param root1: TreeNode
    :param root2: TreeNode
    """
    # If both trees are empty, then they are mirror images 
    if root1 is None and root2 is None: 
        return True

    """ For two trees to be mirror images, the following three 
        conditions must be true 
        1 - Their root node's key must be same 
        2 - left subtree of left tree and right subtree 
        of the right tree have to be mirror images 
        3 - right subtree of left tree and left subtree 
        of right tree have to be mirror images 
    """
    if (root1 is not None and root2 is not None): 
            if root1.val == root2.val: 
                return (isMirror(root1.left, root2.right)and
                isMirror(root1.right, root2.left)) 

    # If neither of the above conditions is true then root1 
    # and root2 are not mirror images 
    return False

def isSymmetric(root: TreeNode):
    """
    Checks if the tree is mirror of itself
    :param root: Tree Node
    """
    # Check if tree is mirror of itself 
    return isMirror(root, root)


# Driver Program 
# Let's construct the tree show in the above figure 
root = TreeNode(1) 
root.left = TreeNode(2) 
root.right = TreeNode(2) 
root.left.left = TreeNode(3) 
root.left.right = TreeNode(4) 
root.right.left = TreeNode(4) 
root.right.right = TreeNode(3) 
print("1" if isSymmetric(root) == True else "0")

# This code is contributed by Nikhil Kumar Singh(nickzuck_007) 

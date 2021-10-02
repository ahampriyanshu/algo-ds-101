"""Invert Binary Tree - Write a function that takes in a Binary Tree and inverts it. In other words, the function should swap every left node in the tree for its corresponding right node. 
Each Binary Tree node has an integer value, a left child node, and a right child node. Children nodes can either be Bina ry Tree nodes themselves or None / null.
"""

# ITERATIVE
# O(N)T | O(N)S

def invertBinaryTree(tree):
    queue = [tree]
    while len(queue) != 0:
        currNode = queue.pop(0)
        if currNode is None:
            continue
        swap(currNode)
        queue.append(currNode.left)
        queue.append(currNode.right)


def swap(tree):
    tree.left, tree.right = tree.right, tree.left


class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# RECURSIVE
# O(N)T | O(d)S


def invertBinaryTree(tree):
    if tree is not None:
        swap(tree)
        invertBinaryTree(tree.left)
        invertBinaryTree(tree.right)
    return


def swap(tree):
    tree.left, tree.right = tree.right, tree.left


# This is the class of the input binary tree.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

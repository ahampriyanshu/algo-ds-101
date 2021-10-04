#!/usr/env/python

class BSTNode:
    def __init__(self, data):  # Node Structure
        self.data = data
        self.left = None
        self.right = None

    """ The data from the nodes should be ordered as left.data <= self.data <= right.data """
    def isValid(self):
        return self is None or (
            (self.left is None or (self.left.data <= self.data and self.left.isValid()))
            and
            (self.right is None or (self.data <= self.right.data and self.right.isValid())))

if __name__ == "__main__":
    bst = BSTNode(5)
    bst.left = BSTNode(3)
    bst.right = BSTNode(8)
    bst.left.left = BSTNode(1)
    bst.left.right = BSTNode(4)

    print(bst.isValid())
    
    nonbst = BSTNode(5)
    nonbst.left = BSTNode(6)
    print(nonbst.isValid())


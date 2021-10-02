'''
Python Code for AVL Tree
@ Author - Sandip Dutta
------------------------------------------------------------------------
$ AVL Tree:

AVL Tree is a special kind of Binary Search Tree. Each node in the
tree, stores a variable called 'BalanceFactor'. Balance Factor
is equal to the difference between the height of the left 
subtree and the right subtree of the node.

    BalanceFactor = (height(left_Subtree) - height(right_Subtree))

In AVL Trees, it is always maintained that the Balance Factor of each 
node is {-1, 0, 1}. This causes the tree to be balanced, that is not 
skewed in one direction or the other.

$ Example of AVL Tree:

           10
           / \
          8  12
         /  /  \
        2  11  15

If we calculate the balance factor for each node, it comes 
out to be {0, 1, -1}.

$ Usefulness:

AVL trees have common operations such as min, max, search all in 
O(log(n)) time complexity.

$ How to maintain balance

AVL achieve balance by using rotations. For more details, see Wikipedia.
'''

class Node(object):
    '''Implement node of a tree.'''

    def __init__(
    self, 
    value, 
    left = None, 
    right = None,    
    height = 1):
        '''Implements the node of the tree.
        @ Args:
        > value - (int) Value of the node
        > left - (int, def - None) left node
        > right - (int, def - None) right node
        > height - (int, def - 1) height of the tree upto the node.
                    Since we need to check height multiple times
                    we store it
        '''
        self.value = value
        self.left = left
        self.right = right
        self.height = height

class AVL_Tree(object):
    '''Implements AVL Tree.'''

    # Helper/utility functions
    def getHeight(self, node):
        '''Returns the height of the node of AVL Tree.
        @ Args:
        > node - (Node) node of a tree. If empty tree, is None
        '''
        if not node:
            return 0
        return node.height
    
    def getBalanceFactor(self, node):
        '''Returns the balance factor of the AVL Tree.
        @ Args:
        > node - (Node) node of a tree. If empty tree, is None
        '''
        if not node:
            return 0
        return self.getHeight(node.left) - self.getHeight(node.right)

    def leftRotate(self, node):
        ''' Performs left rotation on subtree of a node
        rooted at @argument: node.
        @ Args:
        > node - (Node) node of AVL Tree. Empty == None
        @ Return:
        > finalNode - (Node) final Node after left rotation
        '''
        finalNode = node.right # final parent node after rotation
        tempNode = finalNode.left

        # Rotate
        finalNode.left = node
        node.right = tempNode

        # update heights
        node.height = 1 + max(
            self.getHeight(node.left),
            self.getHeight(node.right)
        )
        finalNode.height = 1 + max(
            self.getHeight(finalNode.left),
            self.getHeight(finalNode.right)
        )

        # return finalNode so that parent of 'node' knows 
        # what to point to
        return finalNode

    def rightRotate(self, node):
        ''' Performs right rotation on subtree of a node
        rooted at @argument: node.
        @ Args:
        > node - (Node) node of AVL Tree. Empty == None
        @ Return:
        > finalNode - (Node) final Node after right rotation
        '''
        finalNode = node.left
        tempNode = finalNode.right

        # Rotate right
        finalNode.left = node
        node.right = tempNode

        # Update heights
        node.height = 1 + max(
            self.getHeight(node.left),
            self.getHeight(node.right)
        )

        finalNode.height = 1 + max(
            self.getHeight(finalNode.left),
            self.getHeight(finalNode.right)
        )

        # return finalNode so that parent of 'node' what to 
        # point to
        return finalNode

    def insertNode(self, rootNode, value):
        '''Inserts node in AVL tree as per standard BST rules
        and performs necessary rotations to balance the tree.
        @ Args:
        > rootNode = (Node) The root node of the tree,
                        Empty tree === None
        > value = (int) The value to be inserted
        @ Return:
        > rootNode = (Node) The root node of the tree with value
                    in it's final position
        '''
        if not rootNode: return Node(value) # Empty tree

        # Insert as per BST rules
        if value < rootNode.value:
            rootNode.left = self.insertNode(rootNode.left, value)
        else:
            rootNode.right = self.insertNode(rootNode.right, value)

        # Get balance factor
        balanceFactor = self.getBalanceFactor(rootNode)

        # Perform rotations after insertion
        if balanceFactor > 1:            
            # if below condition is true, we know
            # as per BST rules, value is in left subtree
            # of left subtree of rootNode.
            # As insertion of value caused change in balance
            # We will adjust that subtree so that balance is
            # restored. 
            if value < rootNode.left.value:
                return self.rightRotate(rootNode)
            else:
                # Left skewed tree after insertion
                # but value is greater than value of rootNode
                # Thus, value is the left node of the tree
                # After rotation, update parent node with 
                # new left node.
                rootNode.left = self.leftRotate(root.left)
                return self.rightRotate(root)

        if balanceFactor < -1:
            if value > rootNode.right.value:
                # Adjust right sub tree
                return self.leftRotate(rootNode)
            else:
                # Update parent node
                rootNode.right = self.rightRotate(root.right)
                return self.leftRotate(rootNode)

        return rootNode
# Binary Search Tree (BST) Implementation

class BSTNode:
    def __init__(selfNode, nodeData):  # Node Structure
        selfNode.nodeData = nodeData
        selfNode.left = None
        selfNode.right = None
        selfNode.parent = None

# Insertion Operation

    def insert(selfNode, node):
        if selfNode.nodeData > node.nodeData:
            if selfNode.left is None:
                selfNode.left = node
                node.parent = selfNode
            else:
                selfNode.left.insert(node)
        elif selfNode.nodeData < node.nodeData:
            if selfNode.right is None:
                selfNode.right = node
                node.parent = selfNode
            else:
                selfNode.right.insert(node)

# Removal Operation Functions

    def replace_node_of_parent(selfNode, new_node):
        if selfNode.parent is not None:
            if new_node is not None:
                new_node.parent = selfNode.parent
            if selfNode.parent.left == selfNode:
                selfNode.parent.left = new_node
            elif selfNode.parent.right == selfNode:
                selfNode.parent.right = new_node
        else:
            selfNode.nodeData = new_node.nodeData
            selfNode.left = new_node.left
            selfNode.right = new_node.right
            if new_node.left is not None:
                new_node.left.parent = selfNode
            if new_node.right is not None:
                new_node.right.parent = selfNode

    def find_min(selfNode):
        current = selfNode
        while current.left is not None:
            current = current.left
        return current

    def remove(selfNode):
        if (selfNode.left is not None and selfNode.right is not None):
            successor = selfNode.right.find_min()
            selfNode.nodeData = successor.nodeData
            successor.remove()
        elif selfNode.left is not None:
            selfNode.replace_node_of_parent(selfNode.left)
        elif selfNode.right is not None:
            selfNode.replace_node_of_parent(selfNode.right)
        else:
            selfNode.replace_node_of_parent(None)

# Search required data within BST

    def search(selfNode, nodeData):
        if selfNode.nodeData > nodeData:
            if selfNode.left is not None:
                return selfNode.left.search(nodeData)
            else:
                return None
        elif selfNode.nodeData < nodeData:
            if selfNode.right is not None:
                return selfNode.right.search(nodeData)
            else:
                return None
        return selfNode

# InOrder Traversal Operation

    def inorder(selfNode):
        if selfNode.left is not None:
            selfNode.left.inorder()
        print(selfNode.nodeData, end=' ')
        if selfNode.right is not None:
            selfNode.right.inorder()

# PostOrder Traversal Operation

    def postorder(selfNode):
        if selfNode.left is not None:
            selfNode.left.inorder()
        if selfNode.right is not None:
            selfNode.right.inorder()
        print(selfNode.nodeData, end=' ')

# PreOrder Traversal Operation

    def preorder(selfNode):
        print(selfNode.nodeData, end=' ')
        if selfNode.left is not None:
            selfNode.left.inorder()
        if selfNode.right is not None:
            selfNode.right.inorder()


class BSTree:  # Structure of Binary Search Tree
    def __init__(selfNode):
        selfNode.root = None

    def inorder(selfNode):
        if selfNode.root is not None:
            selfNode.root.inorder()

    def preorder(selfNode):
        if selfNode.root is not None:
            selfNode.root.preorder()

    def postorder(selfNode):
        if selfNode.root is not None:
            selfNode.root.postorder()

    def add(selfNode, nodeData):
        new_node = BSTNode(nodeData)
        if selfNode.root is None:
            selfNode.root = new_node
        else:
            selfNode.root.insert(new_node)

    def remove(selfNode, nodeData):
        to_remove = selfNode.search(nodeData)
        if (selfNode.root == to_remove and selfNode.root.left is None
                and selfNode.root.right is None):
            selfNode.root = None
        else:
            to_remove.remove()

    def search(selfNode, nodeData):
        if selfNode.root is not None:
            return selfNode.root.search(nodeData)


bstree = BSTree()  # Object of class BSTree

# Menu of Operations on BST Tree

print('BST Tree Operation Menu')
print('Add <data>')
print('Remove <data>')
print('Inorder')
print('Preorder')
print('Postorder')
print('Quit')

while True:
    do = input('Enter your action => ').split()

    operation = do[0].strip().lower()
    if operation == 'add':
        nodeData = int(do[1])
        bstree.add(nodeData)
    elif operation == 'remove':
        nodeData = int(do[1])
        bstree.remove(nodeData)
    elif operation == 'inorder':
        print('Inorder Traversal: ', end='')
        bstree.inorder()
        print()
    elif operation == 'postorder':
        print('Postorder Traversal: ', end='')
        bstree.postorder()
        print()
    elif operation == 'preorder':
        print('Preorder Traversal: ', end='')
        bstree.preorder()
        print()
    elif operation == 'quit':
        print("BST Tree Implementation finished.")
        break

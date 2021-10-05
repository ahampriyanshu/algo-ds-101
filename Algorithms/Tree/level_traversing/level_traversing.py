# author: Karthik Hegde
# date: 2/10/2021
# Level order traversal on BST implementation in python


from collections import deque
from typing import List, Optional
import sys


#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def levelOrder(root: TreeNode) -> List[List[int]]:
    traversal = []
    if not root: # if root doesn't exist
        return traversal

    queue = deque([root])
    # level order traversal

    while(queue):
        level_lst =[]
        queue_len = len(queue)

        for i in range(queue_len):
            node = queue.popleft()
            print(node.val)
            level_lst.append(node.val)
            
            if (node.left): # if node.left exists
                queue.append(node.left)
            
            if (node.right): # if node.right exists
                queue.append(node.right)
                
        traversal.append(level_lst)        
        
    return traversal


## ---- taking input and running -----###

def recurse_input(i, node_lst):
    if (i>=len(node_lst) or node_lst[i]=='None'):
        return None
    
    root = TreeNode(int(node_lst[i]))
    root.left = recurse_input(2*i+1, node_lst)
    root.right = recurse_input(2*i+2, node_lst)

    return root

def run():
    ## as input pls give a list of ints 
    # in the input list, children of element at index i are elements at 2*i + 1 and 2*i + 2
    # if particular node is null, type None
    # example input: 0 1 2 None 5 6 None None None 8

    '''
         0
        / \
      1     2
      /\    / 
        5  6
        /
        8
    '''

    node_lst = sys.stdin.readline().split()
    root = recurse_input(0, node_lst)

    lst = levelOrder(root)
    print(lst)

if __name__ == "__main__":
    run()

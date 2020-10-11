"""Max Path Sum In Binary Tree - Write a function that takes in a Binary Tree and returns its max path sum. A path is a collection of connected nodes in a tree where no node is connected to more than two other nodes; a path sum is the sum of the values of the nodes in a particular path. Each BinaryTree node has an integer value , a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null ."""

# For dynamic user input

import unittest

numberList = []
n = int(input("Enter the list size : "))

print("\n")
for i in range(0, n):
    print("Enter number at location", i, ":")
    item = int(input())
    numberList.append(item)

print("User List is ", numberList)


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        test = BinaryTree(1).insert(numberList)
        maxPathSum(test)


class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, values, i=0):
        if i >= len(values):
            return
        queue = [self]
        while len(queue) > 0:
            current = queue.pop(0)
            if current.left is None:
                current.left = BinaryTree(values[i])
                break
            queue.append(current.left)
            if current.right is None:
                current.right = BinaryTree(values[i])
                break
            queue.append(current.right)
        self.insert(values, i + 1)
        return self


# O(N) T | O(1) S


def maxPathSum(tree):
    _, maxSum = findMaxSum(tree)
    return maxSum


def findMaxSum(tree):
    if tree is None:
        return(0, float("-inf"))

    leftSumAsBranch, leftMaxPathSum = findMaxSum(tree.left)
    rightSumAsBranch, rightMaxPathSum = findMaxSum(tree.right)
    maxChildSumAsBranch = max(leftSumAsBranch, rightSumAsBranch)

    value = tree.value
    maxSumAsBranch = max(maxChildSumAsBranch+value, value)
    maxSumUsingRootNode = max(
        maxSumAsBranch, leftSumAsBranch + value + rightSumAsBranch)
    runningMaxPathSum = max(
        leftMaxPathSum, rightMaxPathSum, maxSumUsingRootNode)

    return (maxSumAsBranch, runningMaxPathSum)

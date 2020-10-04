package main

import "fmt"

type treeNode struct {
	value     int
	leftNode  *treeNode
	rightNode *treeNode
}

type tree struct {
	root *treeNode
}

func (binaryTree *tree) reset() {
	binaryTree.root = nil
}

func (binaryTree *tree) insert(value int) {
	binaryTree.insertRec(binaryTree.root, value)
}

func (binaryTree *tree) insertRec(node *treeNode, value int) *treeNode {
	if binaryTree.root == nil {
		binaryTree.root = &treeNode{
			value: value,
		}
		return binaryTree.root
	}
	if node == nil {
		return &treeNode{value: value}
	}
	if value <= node.value {
		node.leftNode = binaryTree.insertRec(node.leftNode, value)
	}
	if value > node.value {
		node.rightNode = binaryTree.insertRec(node.rightNode, value)
	}
	return node
}

func (binaryTree *tree) find(value int) error {
	node := binaryTree.findRec(binaryTree.root, value)
	if node == nil {
		return fmt.Errorf("value: %d not present", value)
	}
	return nil
}

func (binaryTree *tree) findRec(node *treeNode, value int) *treeNode {
	if node == nil {
		return nil
	}
	if node.value == value {
		return binaryTree.root
	}
	if value < node.value {
		return binaryTree.findRec(node.leftNode, value)
	}
	return binaryTree.findRec(node.rightNode, value)
}

func (binaryTree *tree) inorder() {
	binaryTree.inorderRec(binaryTree.root)
}

func (binaryTree *tree) inorderRec(node *treeNode) {
	if node != nil {
		binaryTree.inorderRec(node.leftNode)
		fmt.Println(node.value)
		binaryTree.inorderRec(node.rightNode)
	}
}

func main() {
	binaryTree := &tree{}
	elements := []int{32, 48, 17, -8, 13, 21, 19}
	for _, val := range elements {
		binaryTree.insert(val)
	}

	fmt.Printf("Traversing the tree: Inorder:\n")
	binaryTree.inorder()
	binaryTree.reset()
	elements = []int{-13, -8, 15, 12, 0, 63, 21}
	for _, val := range elements {
		binaryTree.insert(val)
	}

	fmt.Printf("\nTraversing the tree: Inorder:\n")
	binaryTree.inorder()
	fmt.Printf("\nFinding Values:\n")

	toFind := 48
	err := binaryTree.find(toFind)
	if err != nil {
		fmt.Printf("Value %d Not Found\n", toFind)
	} else {
		fmt.Printf("Value %d Found\n", toFind)
	}

	toFind = -33
	err = binaryTree.find(toFind)
	if err != nil {
		fmt.Printf("Value %d Not Found\n", toFind)
	} else {
		fmt.Printf("Value %d Found\n", toFind)
	}

	toFind = 21
	err = binaryTree.find(toFind)
	if err != nil {
		fmt.Printf("Value %d Not Found\n", toFind)
	} else {
		fmt.Printf("Value %d Found\n", toFind)
	}

	toFind = 0
	err = binaryTree.find(toFind)
	if err != nil {
		fmt.Printf("Value %d Not Found\n", toFind)
	} else {
		fmt.Printf("Value %d Found\n", toFind)
	}
}

package main

import "fmt"

type Node struct {
	Value int
	Next *Node
}

func NewNode(value int) *Node {
	return &Node{
		Value: value,
		Next:  nil,
	}
}

func DetectLoop(head *Node) bool {
	slow := head
	fast := head
	for slow != nil && fast != nil && fast.Next != nil{
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast && slow != nil{
			fmt.Println("Loop detected at ",slow.Value)
			return true
		}
	}
	return false
}

func main()  {
	tail := NewNode(0)
	_actualHead := tail
	var intersection *Node
	// creating linked list
	for i := 1; i < 10; i++ {
		n := NewNode(i)
		tail.Next = n
		tail = n

		if i == 5 {
			intersection = tail // marking the loop node
		}
	}
	// completing the loop
	tail.Next = intersection
	if !DetectLoop(_actualHead) {
		fmt.Println("No loop detected")
	}
}





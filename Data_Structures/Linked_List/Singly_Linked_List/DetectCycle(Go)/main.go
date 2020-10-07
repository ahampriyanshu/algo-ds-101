package main

import (
	"fmt"
)

//Node of the linked list
type Node struct {
	data int
	next *Node
}

func push(nodeValue int, head **Node) {
	newNode := &Node{
		next: *head,
		data: nodeValue,
	}

	(*head) = newNode
}

func detectCycle(head *Node) bool {
	if head == nil || head.next == nil {
		return false
	}
	slowPointer := head.next
	fastPointer := head.next.next
	for slowPointer != nil && fastPointer != nil && fastPointer != slowPointer {
		slowPointer = slowPointer.next
		fastPointer = fastPointer.next.next
	}
	if slowPointer != fastPointer {
		return false
	}
	return true
}

func main() {
	var head = &Node{}
	push(1, &head)
	push(2, &head)
	push(3, &head)
	push(4, &head)
	head.next.next.next.next = head

	if detectCycle(head) {
		fmt.Println("Cycle found")
	} else {
		fmt.Println("No Cycle found")
	}
}

package main

import (
	"errors"
	"fmt"
)

// Stack of String values
type Stack []string

func main() {
	var stack Stack

	stack.Push("First")
	stack.Push("Second")
	stack.Push("Third")

	for !stack.IsEmpty() {
		value, _ := stack.Peek()
		fmt.Printf("Peek - First item is: %s\n", value)

		value, _ = stack.Pop()
		fmt.Printf("Pop - popped item: %s\n", value)
	}
}

// IsEmpty returns true if there are no items in the Stack.
func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

// Push appends a new value to the Stack.
func (s *Stack) Push(value string) {
	*s = append(*s, value)
}

// Pop returns and removes the top value in the Stack.
// Returns an error if trying to pop an empty Stack
func (s *Stack) Pop() (string, error) {
	if s.IsEmpty() {
		return "", errors.New("stack is empty")
	}

	i := len(*s) - 1
	value := (*s)[i]
	*s = (*s)[:i]
	return value, nil
}

// Peek returns first value in the Stack without removing
// Returns an error if the Stack is empty
func (s *Stack) Peek() (string, error) {
	if s.IsEmpty() {
		return "", errors.New("stack is empty")
	}

	i := len(*s) - 1
	value := (*s)[i]
	return value, nil
}

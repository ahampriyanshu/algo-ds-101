//https://play.golang.org/p/1RkOVLthUsD

package main

import (
	"fmt"
)

func enqueue(queue []int, ele int) []int {
	queue = append(queue, ele)
	return queue
}

func dequeue() int {
	deleted_ele := queue[0]
	queue = queue[1:]
	return deleted_ele
}

var queue []int

func main() {
	//Enqueue
	queue = enqueue(queue, 1)
	fmt.Println(queue)
	queue = enqueue(queue, 2)
	fmt.Println(queue)
	queue = enqueue(queue, 3)
	fmt.Println(queue)
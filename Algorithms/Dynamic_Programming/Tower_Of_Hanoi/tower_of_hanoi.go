package main

import (
	"fmt"
)

//we will use a two-dimensional slice to hold our stacks
//this representation of the stacks will use the first element of each
//slice as the bottom (i.e. stacks[x][0]). the disc size will be
//represented by the integer value, higher numbers meaning bigger discs
var stacks = [][]int{
	[]int{},
	[]int{},
	[]int{}}

func main() {
	//get tower height from user input
	var towerHeight int
	for towerHeight <= 1 {
		fmt.Println("Enter tower height")
		fmt.Scan(&towerHeight)
	}

	//initialize the first stack
	stacks[0] = make([]int, towerHeight)
	for i := range stacks[0] {
		stacks[0][i] = towerHeight - i
	}

	//display initial stack configuration
	fmt.Println("This is the starting position")
	printStacks()

	moveTower(towerHeight, 0, 2, 1)
}

func moveTower(height int, from int, to int, help int) {
	if height == 1 { //for one-disc-towers, there is nothing else to do but move the disc from start-stack to finish-stack
		moveDisc(height, from, to)
	} else { //for towers with more than one disk, we use recursion to
		moveTower(height-1, from, help, to) //move a smaller tower (all discs but the bottom) to the helper-stack
		moveDisc(height, from, to)          //then move the bottom disc to the finish-stack
		moveTower(height-1, help, to, from) //and finally move the smaller tower from the helper stack on top of the bottom disk that now sits on the finish-stack
	}
}

func moveDisc(index int, from int, to int) {
	disc := stacks[from][len(stacks[from])-1]         //get last element of the origin array
	stacks[from] = stacks[from][:len(stacks[from])-1] //new origin array will contain everything except the last element
	stacks[to] = append(stacks[to], disc)             //append that element to the destination array

	fmt.Printf("Move disc %d from stack %d to stack %d\n", index, from+1, to+1)
	printStacks()
}

func printStacks() {
	//for the sake of simplicity, the display will just print out the slices
	for _, stack := range stacks {
		fmt.Println(stack)
	}
	fmt.Println()
}

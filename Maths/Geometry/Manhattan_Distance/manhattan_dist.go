package main

import (
	"fmt"
	"math"
)

func calcManhattanDist(x1, y1, x2, y2 int) {
	dist := math.Abs(float64(x1 - x2)) + math.Abs(float64(y1 - y2))
	fmt.Println(dist)
}

func main() {
	calcManhattanDist(2, 5, 10, 14)
}
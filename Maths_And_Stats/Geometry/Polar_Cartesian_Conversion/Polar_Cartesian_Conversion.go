/*
	This code takes input r and θ in Polar Coordinates and converts them into cartesian coordinates.
	Language : Golang
	Author : Pulkit Sapra
*/

package main

//Package fmt implements formatted I/O with functions analogous to C's printf and scanf. 
import (
	"fmt"
	"math"
	)

func convert_to_cartesian(r float64, theta float64){
	var x,y float64

	//convert degree to radians
	theta = theta*math.Pi/180 

	//Conversion of polar coord. to Cartesian
	x = r * math.Cos(theta)
	y = r * math.Sin(theta) 

	fmt.Printf("x = %0.3f, y = %0.3f\n", x , y)

}

// Main Function
func main() {
	fmt.Print("Please enter radius(r) and theta(in degree) : ")
	
	// Declaring variables and their types.
	var r,theta float64

	// Taking input for r adn theta
	fmt.Scan(&r)
	fmt.Scan(&theta)

	//Function call
	convert_to_cartesian(r,theta)
	
}

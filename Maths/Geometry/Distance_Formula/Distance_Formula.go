package main

import "fmt"
import "strconv"
import "math"

func main() {
	
	//Getting input of user for x1,x2,y1 and y2 coordinates then converting them to float types if numeric values are not entered then program stops.
	
	fmt.Println("Enter X1 coordinate: ")
	var x1 string
	fmt.Scanln(&x1)
	convX1,err:= strconv.ParseFloat(x1,64)
	if err!=nil{
		fmt.Println("Bad Input please enter numeric values only for X1.")
		return
	}
	fmt.Println("Enter Y1 coordinate: ")
	var y1 string
	fmt.Scanln(&y1)
	convY1,err:= strconv.ParseFloat(y1,64)
	
	if err!=nil{
		fmt.Println("Bad Input please enter numeric values only for Y1.")
		return
	}

	fmt.Println("Enter X2 coordinate: ")
	var x2 string
	fmt.Scanln(&x2)
	convX2,err:= strconv.ParseFloat(x2,64)
	
	if err!=nil{
		fmt.Println("Bad Input please enter numeric values only for X2.")
		return
	}
	
	fmt.Println("Enter Y2 coordinate: ")
	var y2 string
	fmt.Scanln(&y2)
	convY2,err:= strconv.ParseFloat(y2,64)
	
	if err!=nil{
		fmt.Println("Bad Input please enter numeric values only for Y2:",)
		return
	}
	
	//calculating difference between x1,x2 and y1,y2 coordinates

	diffXC:= math.Abs(convX2-convX1)
	diffYC:= math.Abs(convY2-convY1)

	//Calculating squares of the differences obtained above.
	
	squX:=diffXC*diffXC
	squY:=diffYC*diffYC

	//Calculating the final distance after adding and finding the square root.
	totalDistance:=math.Sqrt(squX+squY)
	fmt.Printf("The distance between the two points (x1=%0.2F,y1=%0.2F) and (x2=%0.2F,y2=%0.2F) is %0.2F\n",convX1,convY1,convX2,convY2,totalDistance)

}

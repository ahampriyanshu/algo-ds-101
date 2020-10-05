package main

import (
	"fmt"
	"math"
)

// use consts instead of "magic numbers"
const minutesPerHour = 60
const hourHandDegreePerMinute = 0.5
const minuteHandDegreePerMinute = 6

// Calculate clock angle between hour hand and minute hand in degrees
// Where:
// hours in range 0 - 12
// minutes in range 0 -59
func clockAngle(hours uint, minutes uint) (float64, error) {
	// Check user input
	if hours < 0 || minutes < 0 || hours > 12 || minutes > 59 {
		return 0, fmt.Errorf("Invalid input:\n0 < hour < 12 and 0 < minute < 59")
	}

	hourAngle := hourHandDegreePerMinute * float64((hours * minutesPerHour + minutes))
	minuteAngle := float64(minuteHandDegreePerMinute * minutes)

	angle := math.Abs(hourAngle - minuteAngle)

	return angle, nil
}

func main() {
	var (
		hours uint
		minutes uint
	)

	// Get user input
	fmt.Printf("Please enter hours and minutes separated by a space where h(0-12) m(0, 59): ")
	_, err := fmt.Scanf("%d%d", &hours, &minutes)
	if err != nil {
		fmt.Println("Invalid input type, decimal values required !")
		return
	}

	// Calculate and display the clock angle based on a 12 hour clock
	angle, err := clockAngle(hours, minutes)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Printf("The angle between hour hand and minute hand is %.2f (deg)", angle)
}
package main

import "fmt"

func getEasterDate(_year int) {
	a := (19 * (_year % 19) + 15) % 30
	b := (2 * (_year % 4) + 4 * (_year % 7) + 6 * a + 6) % 7

	var _date string
	if a + b > 26 {
		_date =  fmt.Sprintf("May %d", (a + b - 26))
	} else {
		_date =  fmt.Sprintf("April %d", (4 + a + b))
	}

	fmt.Println(_date, _year)
}

func main() {
	getEasterDate(2020)
}
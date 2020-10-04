package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func reverse(s string) string {
	chars := []rune(s)
	for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
		chars[i], chars[j] = chars[j], chars[i]
	}
	return string(chars)
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter Text to check for Palindrome. Press Ctrl-C to Quit.")
	fmt.Println("---------------------")

	for {
		fmt.Print("-> ")
		text, _ := reader.ReadString('\n')
		// convert CRLF to LF
		text = strings.Replace(text, "\n", "", -1)

		if strings.Compare(text, reverse(text)) == 0 {
			fmt.Println("Palindome!")
		} else {
			fmt.Println("Nope.")
		}
	}

}

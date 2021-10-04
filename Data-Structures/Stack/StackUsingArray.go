package main
import (
	"fmt"
)

type stack []int

func (s stack) push(v int) stack {
    return append(s, v)
}

func (s stack) pop() (stack, int) {
    l := len(s)
   { return  s[:l-1], s[l-1]}
}

func (s stack) size() int {
    return len(s)
}

func main(){
    s := make(stack,0)
    s = s.push(101)
    s = s.push(203)
    s = s.push(399)
    s = s.push(501)
    s, p := s.pop()
    fmt.Println(p)
    fmt.Println( s.size())
	

}

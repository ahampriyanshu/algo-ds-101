//Jump Search implementation in Golang.

package main
import "fmt"
import "math"


func main() {

  arr := []int{ 0, 1, 2, 4, 9, 16, 25, 36, 64, 81, 100, 121, 144, 189, 400, 625}
  n:= len(arr)
  x:= 144


  z:= jumpSearch(arr, x, n)
  fmt.Println("Number found at index",z)

}

func jumpSearch(arr []int, x int, n int) (inx float64){

  step:= math.Round(math.Sqrt(float64(n)))
  var i float64
  for i= 0; i < float64(n); i+=step {
    if (arr[int(i)] > x){
      break;
    }
  }
  i = i - step
  ub:= i + step
  for ; i < ub; i++{
    if(arr[int(i)]==x){
      return i;
    }
  }
  return -1;
}

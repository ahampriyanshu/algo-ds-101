import UIKit
let num=readline()
var a=Int(num!)
func factorial(a: Int) -> Int {
    let n = a
    if(n == 1){
      return 1
    }else{
      return n*factorial(n-1)
    }
}
factorial(a: a)
import Foundation

class Fibonacci {
    var array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    func fibonacciOfArray(_ array:[Int]) {
        for item in array {
            print("Fibonacci (\(item)): ", fibonacci(item))
        }
    }
    
    func fibonacci(_ n: Int) -> Int {
        if n <= 1 {
            return n;
        } else {
            return fibonacci(n-1) + fibonacci(n-2)
        }
    }
}

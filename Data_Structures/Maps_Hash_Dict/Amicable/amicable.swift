// returns true if two numbers are amicable
func isAmicable(_ a : Int, _ b : Int) -> Bool {
    return getSum(num: a) == b && getSum(num: b) == a
}

// returns a sum of all of the factors of a Int
func getSum(num a: Int) -> Int {
    var sum : Int = 0;
    // check for factors
    for i in 1 ..< a {
        // add to sum if remainder is 0
        if a % i == 0 {
            sum += i;
        }
        
    }
    return sum;
}

// driver code
print(isAmicable(284, 220)) // true
print(isAmicable(6, 12))    // false

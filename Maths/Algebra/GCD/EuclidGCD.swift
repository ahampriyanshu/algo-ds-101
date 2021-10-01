//
//  EuclidGCD.swift
//  Hacktoberfest
//
//  Created by Dipankar Goswami on 03/10/20.
//

import Foundation

func getGCD(input1: Int, input2: Int) -> Int {
    
    var bigger = max(input1, input2)
    var smaller = min(input1, input2)

    while smaller > 0 {
        let rem = bigger % smaller
        bigger = smaller;
        smaller = rem
    }

    return bigger
}

var number1 = Int(readLine()!)!
var number2 = Int(readLine()!)!

let res = getGCD(input1: number1, input2: number2)
print("GCD of \(number1) and \(number2) is \(res)")

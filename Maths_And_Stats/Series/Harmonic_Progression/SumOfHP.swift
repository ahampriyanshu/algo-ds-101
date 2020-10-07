//
//  SumOfHP.swift
//  Hacktoberfest
//
//  Created by Dipankar Goswami on 03/10/20.
//

import Foundation

func getHPSum(first_term: Double, common_diff: Double, no_of_terms: Int) -> Double {
    var res:Double = 0.0
    for i in 0...no_of_terms-1 {
        res = res + 1/(first_term + Double(i) * common_diff)
    }
    return res
}

var first_term = Double(readLine()!)!
var common_diff = Double(readLine()!)!
var no_of_terms = Int(readLine()!)!

/* Following Code blocm checks if any of the term in arithmatic progression can be zero.
    In that case corresponding term in HP is undefined.
    Checks are -
    1. If first term is zero.
    2. if negative of (first_term/common_diff) is a positive integer between 1 and number of terms (inclusive)
 */
if first_term == 0 ||
    (common_diff != 0 && Int(first_term) % Int(common_diff) == 0
        && (Int(first_term/common_diff ) * (-1) < no_of_terms && Int(first_term/common_diff) * -1 > 0)) {
    print("Harmonic progression potentially contains zero as one of the terms.")
} else {
    let res = getHPSum(first_term: first_term, common_diff: common_diff, no_of_terms: no_of_terms)
    print("Sum of Harmonic progression for given inputs is \(res)")
}


import Foundation

func getStdDeviation(input:[Int], population: Bool = true) -> Double {
    var sq_sum = 0.0
 
    //Calculate Mean of given inout array
    var sum = 0
    for number in input {
        sum += number
    }
    let mean = Double(sum) / Double(input.count)

    //calculate the sum of squared difference between mean and each element in the input
    for number in input {
        sq_sum = sq_sum + pow(Double(number) - mean, 2)
    }

    //Divisor depends on if its population stddev or sample stddev
    let div = population ? input.count : input.count - 1
    
    return sqrt(sq_sum / Double(div))
}

let input = readLine()!.split(separator: " ").map { Int(String($0))! }

let population_stdDev = getStdDeviation(input: input)
print("Population Standard Deviation for given input series is \(population_stdDev)")

let sample_stdDev = getStdDeviation(input: input, population: false)
print("Sample Standard Deviation for given input series is \(sample_stdDev)")

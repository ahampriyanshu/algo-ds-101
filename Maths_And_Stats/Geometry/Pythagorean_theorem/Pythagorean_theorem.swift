import Foundation

func isPythagorean(_ sideA: Float64, _ sideB: Float64, _ sideC: Float64) -> Bool {
    let sideA_squared = sideA * sideA
    let sideB_squared = sideB * sideB
    let sideC_squared = sideC * sideC

    return (sideA_squared == sideB_squared + sideC_squared)
        || (sideB_squared == sideA_squared + sideC_squared)
        || (sideC_squared == sideA_squared + sideB_squared)
}

print("Enter side A:")
let sideAinString = readLine(strippingNewline: true)

print("Enter side B:")
let sideBinString = readLine(strippingNewline: true)

print("Enter side C:")
let sideCinString = readLine(strippingNewline: true)

if let sideA = Double(sideAinString!), let sideB = Double(sideBinString!), let sideC = Double(sideCinString!) {
    print(isPythagorean(sideA, sideB, sideC))
} else {
    print("Input value cannot be converted to a number")
}
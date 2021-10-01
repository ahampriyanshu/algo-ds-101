
//This function checks the 3 numbers. If they form a pythagorean triplet, it finds out hypotenuse and legs
// else it return null
const checkPythagoreanTriplet = (a, b, c) => {
    if (!a || !b || !c) {
        return null;
    }
    if (a * a + b * b === c * c) {
        return { hypotenuse: c, legs: [a, b] }
    }
    else if (a * a + c * c === b * b) {
        return { hypotenuse: b, legs: [a, c] }
    }
    else if (c * c + b * b === a * a) {
        return { hypotenuse: a, legs: [c, b] }
    }
    return null;
}

console.log(checkPythagoreanTriplet(3, 4, 5),
    checkPythagoreanTriplet(13, 12, 5),
    checkPythagoreanTriplet(3, 4, 6))

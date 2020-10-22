function babylonianSqrt(n) {

  // Checks for valid number input
  if (!(typeof n === 'number' && n >= 0 && !isNaN(n))) {
    return NaN;
  } else if (n === 0) {
    return 0;
  } else if (n === Infinity) {
    return Infinity;
  }

  var value = n;

  while (true) {
    var last = value;

    // Calculate value
    value = (value + n / value) * 0.5;
    // Check if true
    if (Math.abs(value - last) < 1e-9) {
      break;
    }
  }

  return value;
}

// Test
let userInput = parseInt(prompt("Enter a number to find the Babylonian square root:"))

babylonianSqrt(userInput);

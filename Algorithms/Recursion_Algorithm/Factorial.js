function factorial(n) {
  var negativeSign = n < 0;
  if (negativeSign) {
    throw new Error("Negative number", "Please enter a positive number");
  }
  if (n === 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

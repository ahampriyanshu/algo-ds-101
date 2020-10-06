// Recursion implementation (factorial) in JavaScript

function factorialize(num) {
  if (num < 0)  // If the number is less than 0, reject it.
    return -1;
  else if (num == 0) // If the number is 0, its factorial is 1.
    return 1;
  else {
    return (num * factorialize(num - 1));  // Otherwise, call the recursive function again
  }
}

console.log(factorialize(5)); // The result is 120

/*
If we sum up all the calls in one line, we have
(5 * (5 - 1) * (4 - 1) * (3 - 1) * (2 - 1)) = 5 * 4 * 3 * 2 * 1 = 120
*/
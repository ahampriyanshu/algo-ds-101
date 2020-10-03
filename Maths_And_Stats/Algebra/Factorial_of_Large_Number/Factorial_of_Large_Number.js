/*
  Factorial simply tells us to multiply any natural number by all the natural numbers that are smaller than it. 
  
  Example :
  If we're asked to evaluate 5!, I simply have to do 5 * 4 * 3 * 2 * 1, and I get 120.
*/

// Recursive function to calculate factorial of a large number 

const largeNumberFactorial = (num) => {
  if (num === 0n) return 1n;
  return num * largeNumberFactorial(num - 1n);
};


const number = 50;

// Calling Function
const factorial = String(largeNumberFactorial(BigInt(number)));

console.log(`Factorial of ${number} is ${factorial}`);

/*
  Output : 
  Factorial of 50 is 30414093201713378043612608166064768844377641568960512000000000000
*/


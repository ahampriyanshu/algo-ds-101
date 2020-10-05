// Take Input from user
var nTerm = parseInt(
  prompt(
    "Enter the nth term upto which you want to calculate the sum of n sqaure "
  )
);

// Get the Sum of n square
var value = () => {
  return (nTerm * (nTerm + 1) * (2 * nTerm + 1)) / 6;
};

// Print it
console.log(value());

// function to calculate distance between two points
const distanceFormula = (x1, y1, x2, y2) => {
  const x_diff = x2 - x1;
  const y_diff = y2 - y1;
  return Math.sqrt(x_diff * x_diff + y_diff * y_diff);
};

// Take two points as input
let x1 = prompt("Enter x value of first point: ");
let y1 = prompt("Enter y value of first point: ");
let x2 = prompt("Enter x value of second point: ");
let y2 = prompt("Enter x value of second point: ");

// output
console.log(distanceFormula(x1, y1, x2, y2));

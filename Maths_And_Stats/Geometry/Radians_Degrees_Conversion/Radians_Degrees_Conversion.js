const pi = 3.1415926535;

// function to convert degrees to radians
const degreesToRadians = (degrees) => {
  return degrees * (pi / 180);
};

// function to convert radians to degrees
const radiansToDegrees = (radians) => {
  return radians * (180 / pi);
};

//driver code
const degreeInput = prompt("Enter a number to convert from degree to radian: ");
let radianOutput = degreesToRadians(degreeInput);
console.log(`${degreeInput}° = ${radianOutput} rad`);

const radianInput = prompt("Enter a number to convert from radian to degree: ");
let degreeOutput = radiansToDegrees(radianInput);
console.log(`${radianInput} rad = ${degreeOutput}°`);

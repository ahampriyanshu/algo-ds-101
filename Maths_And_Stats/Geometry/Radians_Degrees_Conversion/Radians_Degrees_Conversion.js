const { log } = require("console");

const pi = 3.1415926535;

// function to convert degrees to radians
const degreesToRadians = (degrees) => {
  return degrees * (pi / 180);
};

// function to convert radians to degrees
const radiansToDegrees = (radians) => {
  return radians * (180 / pi);
};

// Setup I/O
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

//prompt asks for degree to convert to radian
readline.question("Enter number to convert from degree to radian: ", (num) => {
  const result = degreesToRadians(num);
  console.log(`${num}° = ${result} rad`);
  //verify answer by running radian to degree conversion on result
  const verify = radiansToDegrees(result);
  console.log(`${result} rad = ${verify}°`);
  readline.close();
});

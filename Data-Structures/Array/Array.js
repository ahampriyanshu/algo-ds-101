// Importing the module
const readline = require("readline-sync");
  
// Enter the size of an array
let size = Number(readline.question("Enter the size of an array: "));

// Initializing an empty array
let number = [];

// Storing the values in the array
for (let i = 0; i < size; ++i) {
  number.push(Number(readline.question("Enter the value for element "+ ( i+1 ) +" : " )));
}

//Traversing through the array
console.log("The array elements are: ")
for(let i = 0; i < size; ++i){
    console.log(number[i]);
}

// This is required for console input
var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Number of terms to be found: ", function(answer) {
    let first = 2;
    let second = 1;
    let result;
    console.log(first);
    console.log(second);
  for (let i = 0; i < +answer - 2; i++) {
    result = first + second;
    console.log(result);
    first = second;
    second = result;
  }
  rl.close();
});

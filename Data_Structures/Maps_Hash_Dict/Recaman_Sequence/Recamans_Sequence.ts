// This is required for console input
var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Number of terms to be found: ", function(answer) {
  let list = [];
  list[0] = 0;
  console.log(list[0]);
  for (let n = 1; n < +answer; n++) {
    if (list[n-1] - n > 0 && !list.includes(list[n-1] - n)) {
        list[n] = list[n-1] - n;
    } else {
        list[n] = list[n-1] + n;
    }
    console.log(list[n]);
  }
  rl.close();
});

const readline = require('readline');

const r1 = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

r1.question('Input a word to check if it is a palindrome: ', (word) => {
  const isPalindrome = palindromeCheck(word);

  if (!isPalindrome) {
    console.log('It is NOT a palindrome!')
  } else {
    console.log('It is a palindrome!');
  }

  process.exit(1);
});

function palindromeCheck(word) {
  return word.split('').reverse().join('') === word;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question(
  'Input a string to find the longest palindromic substring: ',
  (str) => {
    console.log(
      `The longest palindromic substring is: ${longestPalSubstr(str)}`
    );
    rl.close();
  }
);

// Examples
// HeyrailataLiarLiveonoevilBye  ==>  railataliar
// Ratsliveonnoevilstar  ==>  ratsliveonnoevilstar
// abraCadabra ==>  aca

function longestPalSubstr(str) {
  const n = str.length; // length of input string

  const s = str.toLowerCase(); // the new string in lowercase to work with

  // Set a matrix to check substrings (default values to false)
  // - matrix[i][j] will be false if substring str[i..j] is not palindrome
  // - otherwise, matrix[i][j] will be true
  const matrix = new Array(n);
  for (let i = 0; i < n; i++) {
    matrix[i] = Array(n).fill(false);
  }

  // All substrings of length 1 are palindromes
  let maxLength = 1;
  for (let i = 0; i < n; i++) {
    matrix[i][i] = true;
  }

  // Check for substring of length 2.
  let start = 0;
  for (let i = 0; i < n - 1; i++) {
    if (s[i] === s[i + 1]) {
      matrix[i][i + 1] = true;
      start = i;
      maxLength = 2;
    }
  }

  // Check for lengths greater than 2.
  // k is length of substring
  for (let k = 3; k <= n; k++) {
    // Starting index
    for (let i = 0; i < n - k + 1; i++) {
      // Ending index of substring from starting index i and length k
      const j = i + k - 1;

      // Checking for substring from ith index to jth index
      // if str.charAt(i+1) to str.charAt(j-1) is a palindrome
      if (matrix[i + 1][j - 1] && s[i] === s[j]) {
        matrix[i][j] = true;
        if (k > maxLength) {
          start = i;
          maxLength = k;
        }
      }
    }
  }
  return s.slice(start, start + maxLength);
}

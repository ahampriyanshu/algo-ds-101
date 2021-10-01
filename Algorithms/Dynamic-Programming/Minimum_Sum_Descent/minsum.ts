/* Implementation of Dynamic programming
of Minimum sum descent in TypeScript
*/

const minSum = (triangle: number[][]) => {
  let memo: number[] = [];
  let n = triangle.length - 1;

  // memo for bottom row
  for (let i = 0; i < triangle[n].length; i++) {
    memo[i] = triangle[n][i];
  }

  // Calculating the remaining rows in bottom-up manner
  for (let i = triangle.length - 2; i >= 0; i--) {
    for (let j = 0; j < triangle[i].length; j++) {
      memo[j] = triangle[i][j] + Math.min(memo[j], memo[j + 1]);
    }
  }

  return memo[0];
};

const triangle = [[2], [3, 9], [1, 6, 7]];
console.log(minSum(triangle));

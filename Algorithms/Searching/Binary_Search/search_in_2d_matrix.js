function binarySearch(mat, i, j_low, j_high, x) {
  while (j_low <= j_high) {
    let j_mid = Math.floor((j_low + j_high) / 2);

    // Element found
    if (mat[i][j_mid] == x) {
      document.write("Found at (" + i + ", " + j_mid + ")");
      return;
    } else if (mat[i][j_mid] > x) j_high = j_mid - 1;
    else j_low = j_mid + 1;
  }

  // Element not found
  document.write("Element no found<br>");
}

// Function to perform binary search on the mid
// values of row to get the desired pair of rows
// where the element can be found
function sortedMatrixSearch(mat, n, m, x) {
  // Single row matrix
  if (n == 1) {
    binarySearch(mat, 0, 0, m - 1, x);
    return;
  }

  // Do binary search in middle column.
  // Condition to terminate the loop when the
  // 2 desired rows are found
  let i_low = 0;
  let i_high = n - 1;
  let j_mid = Math.floor(m / 2);

  while (i_low + 1 < i_high) {
    let i_mid = Math.floor((i_low + i_high) / 2);

    // Element found
    if (mat[i_mid][j_mid] == x) {
      document.write("Found at (" + i_mid + ", " + j_mid + ")");
      return;
    } else if (mat[i_mid][j_mid] > x) i_high = i_mid;
    else i_low = i_mid;
  }

  // If element is present on
  // the mid of the two rows
  if (mat[i_low][j_mid] == x)
    document.write("Found at (" + i_low + "," + j_mid + ")");
  else if (mat[i_low + 1][j_mid] == x)
    document.write("Found at (" + (i_low + 1) + ", " + j_mid + ")");
  // Search element on 1st half of 1st row
  else if (x <= mat[i_low][j_mid - 1])
    binarySearch(mat, i_low, 0, j_mid - 1, x);
  // Search element on 2nd half of 1st row
  else if (x >= mat[i_low][j_mid + 1] && x <= mat[i_low][m - 1])
    binarySearch(mat, i_low, j_mid + 1, m - 1, x);
  // Search element on 1st half of 2nd row
  else if (x <= mat[i_low + 1][j_mid - 1])
    binarySearch(mat, i_low + 1, 0, j_mid - 1, x);
  // search element on 2nd half of 2nd row
  else binarySearch(mat, i_low + 1, j_mid + 1, m - 1, x);
}

// Example code
let n = 4,
  m = 5,
  x = 8;
let mat = [
  [0, 6, 8, 9, 11],
  [20, 22, 28, 29, 31],
  [36, 38, 50, 61, 63],
  [64, 66, 100, 122, 128],
];

sortedMatrixSearch(mat, n, m, x);

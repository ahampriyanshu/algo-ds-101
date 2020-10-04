function multiply(a, b) {

    const aNumRows = a.length, aNumCols = a[0].length,
        bNumRows = b.length, bNumCols = b[0].length,
        m = new Array(aNumRows);  // initialize array of rows

    for (let r = 0; r < aNumRows; ++r) {

        m[r] = new Array(bNumCols); // initialize the current row

        for (let c = 0; c < bNumCols; ++c) {
          m[r][c] = 0;             // initialize the current cell
          for (let i = 0; i < aNumCols; ++i) {
            m[r][c] += a[r][i] * b[i][c];
          }
        }
    }
    return m;
}


function display(m) {
  for (let r = 0; r < m.length; ++r) {
    console.log('\t'+m[r].join(' ')+'\n');
  }

}



const a = [[8, 3, 4], [2, 4, 5], [3, 6, 2]],
    b = [[1, 2, 3], [4, 6, 8], [3, 8, 1]];


console.log('matrix a:\n');
display(a);
console.log('matrix b:\n');
display(b);
console.log('a * b =\n');
display(multiply(a, b));
/*
Arithmetic progression if a sequence of number has same common difference. 
Here
    a is first term of series
    d is common difference
    n is number of terms
*/

const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

const inputParams = () => new Promise(resolve =>
    rl.question('\nEnter first term (a)\n> ', a =>
        rl.question('Enter common difference (d)\n> ', d =>
            rl.question('Enter the number of elements (n) \n> ', n => {
                a = parseInt(a)
                d = parseInt(d)
                n = parseInt(n)
                rl.close()
                resolve({ a, d, n })
            })
        )
    )
)

const sumOfAP = (a, d, n) => {
    let sum = 0;
    let i = 0;
    while (i < n) {
        sum += a;
        a += d;
        i++;
    }
    return sum;
}

inputParams()
    .then(({ a, d, n }) => {
        console.log(`\nSum of arithmetic progression: \
  ${sumOfAP(a, d, n)}`)
    })
/*
For testin purpose
let a = 1;
let d = 1.5;
let n = 10;

console.log(sumOfAP(a, d, n));
*/

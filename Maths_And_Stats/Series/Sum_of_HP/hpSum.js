const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

// Basic implementation
const hpSum = (a, d, n) => {
  let sum = 0;
  for (let i = 0; i < n; i++) {
    sum += 1 / (a + i * d)
  }
  return sum
}

// Recursive implementation
const hpSumRecursive = (a, d, limit, sum = 0) =>
  limit > 0 ?
    hpSumRecursive(a, d, limit - 1, sum + 1 / (a + (limit - 1) * d)) :
    sum

const askQuestions = () => new Promise(resolve  => 
  rl.question('\nEnter a\n> ', a =>
    rl.question('Enter d\n> ', d =>
      rl.question('Enter the number of elements\n> ', n => {
        a = parseInt(a)
        d = parseInt(d)
        n = parseInt(n)
        rl.close()
        resolve({ a, d, n })
      })
    )
  )
)

askQuestions()
  .then(({ a, d, n }) => {
    console.log(`\nA sum of a harmonic progression (basic alg) is \
${hpSum(a, d, n)}`)
    console.log(`A sum of a harmonic progression (recursive alg) is \
${hpSum(a, d, n)}\n`)
  })

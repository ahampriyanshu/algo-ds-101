const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('\nFor which year do you want to know Easter date?\n> ', year => {
  year = parseInt(year)

  const a = (19 * (year % 19) + 15) % 30
  const b = (2 * (year % 4) + 4 * (year % 7) + 6 * a + 6) % 7

  console.log(`Easter date in ${year} is \
${a + b > 26 ? 'May ' + (a + b - 26) : 'April ' + (4 + a + b)}\n`)

  rl.close()
})

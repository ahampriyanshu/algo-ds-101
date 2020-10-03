const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
const lcm = (...arr) => {
	let newArray = arr.toString().split(' ');
	const gcd = (x, y) => (!y ? x : gcd(y, x % y));
	const lcm = (x, y) => (x * y) / gcd(x, y);
	return [...newArray].reduce((a, b) => lcm(a, b));
};
rl.question('Enter space seperated positive Integers ', (input)=> {
	console.log(lcm(input));
	rl.close()
})

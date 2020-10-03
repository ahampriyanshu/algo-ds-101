const lcm = (...arr) => {
	const gcd = (x, y) => (!y ? x : gcd(y, x % y));
	const lcm = (x, y) => (x * y) / gcd(x, y);
	return [...arr].reduce((a, b) => lcm(a, b));
};
//prints the LCM value
console.log(lcm(12, 7)); // returns 84
console.log(lcm(10, 20)); // returns 20
console.log(lcm(100, 90)); //returns 900

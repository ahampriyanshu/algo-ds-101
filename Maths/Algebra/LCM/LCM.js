let lcm = (n1, n2) => {
  //Find the smallest and biggest number from both the numbers
  let lar = Math.max(n1, n2);
  let small = Math.min(n1, n2);

  //Loop till you find a number by adding the largest number which is divisble by the smallest number
  let i = lar;
  while (i % small !== 0) {
    i += lar;
  }

  //return the number
  return i;
};

console.log(lcm(12, 13));
console.log(lcm(9, 3));

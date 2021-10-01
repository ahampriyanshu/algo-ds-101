let findPrimeFactors = (num: number) => {
    const arr: number[] = [];
    for (let i: number = 2; i <= num; i++) {
      while ((num % i) === 0) {
        arr.push(i);
        num /= i;
      }
  }
  return arr;
}


findPrimeFactors(777)

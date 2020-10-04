const getAllPrimesUpToNumber = (num: number): number[] => {
  //Prefill array up to max num.
  const maxNumArray: boolean[] = new Array(num).fill(true)

  //Won't find any primes > sqrt of num.
  const limit = Math.floor(Math.sqrt(num))

  //Increment by 2, as no even numbers besides 2 are prime.
  for (let i = 3; i < limit; i += 2) {
    if (maxNumArray[i]) {
      //Remove multiples of primes.
      for (let j = i * i; j < num; j += i * 2) {
        maxNumArray[j] = false
      }
    }
  }

  //Initialize with 2, as it is the only even prime and we have not checked them.
  const primes: number[] = [2]

  //Push all items that are truthy to primes array.
  for (let i = 3; i < num; i += 2) {
    maxNumArray[i] && primes.push(i)
  }

  return primes
}

console.log(getAllPrimesUpToNumber(10000000))

const uglyNumber = (number) => {

    //determine if a number is prime
    const numIsPrime = (num) => {
        for (let i = 2; i <= Math.sqrt(num); i++) {
            if (num % i === 0) {
                return false;
            }
        }
        return num > 1;
    } 

    const primeFactors = [];
    const uglyPrimeFactors = [2, 3, 5]
    
    //push distinct prime factors to the array
    for (let i = 2; i <= number; i++) {
        while (numIsPrime(i) && number % i === 0) {
            if (!primeFactors.includes(i)) {
                primeFactors.push(i);
            }
            number /= i;
        }
    }

    //find out if number is an ugly number i.e has prime factors consisting of 2, 3, or 5
    const numberIsUgly = primeFactors.some(factor => uglyPrimeFactors.includes(factor)) ? true : false;

    return numberIsUgly;
}

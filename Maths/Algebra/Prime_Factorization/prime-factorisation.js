/*Explanation=> The following code is to calculate all the prime factors of a desired number "num" 
Steps followed :-
1. Took input num;
2. Made a for loop to traverse through 2 to num and check the number completely divisible by num using (num%i ==0)
3.Made another loop to see if the number is prime or not 
4.If prime then push it into the array and print out 
*/


let findPrimeFactors = (num) => {
    let arr = [];


    for ( var i = 2; i < num; i++) {
        let isPrime
        if (num % i === 0) {
            isPrime = true;
            for (var j = 2; j <= i; j++) {
                if ( i % j === 0) {
                isPrime == false;
                }
            } 
        }if (isPrime == true) { arr.push(i)}

    }console.log(arr)
}

findPrimeFactors(num);
function segmented_sieve(n){
    //Create an boolean array with all values True
    var primes = new Array(n).fill(true)

    for(var i=2;i<=n;i++){
        //If prime[p] is True,it is a prime and its multiples are not prime
        if(primes[i]){
            for(var j=i*2;j<=n;j+=i){

                //Mark every multiple of a prime as not prime
                primes[j]=false
            }
        }
    }
    //If value is true it is prime and print value
    for(var k=2;k<n;k++){
        if(primes[k])
            console.log(k)
    }
}

//Test
let number = prompt("Enter a positive integer")
segmented_sieve(parseInt(number))
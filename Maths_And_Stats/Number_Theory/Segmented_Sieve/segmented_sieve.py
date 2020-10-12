def segmented_sieve(n):

    # Create an boolean array with all values True
    primes = [True]*n

    for p in range(2,n):
        #If prime[p] is True,it is a prime and its multiples are not prime

        if primes[p]:
            for i in range(2*p,n,p):

                # Mark every multiple of a prime as not prime
                primes[i]=False

    #If value is true it is prime and print value
    for l in range(2,n):
        if primes[l]:
            print(f"{l} ")

#Test
while True:
    try:
        input_value = int(input("Please a number: "))
        segmented_sieve(input_value)
        break
    except ValueError:
        print("No valid integer! Please try again ...")
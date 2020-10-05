/*
This is a Java program to find prime numbers up to a limit
using the Sieve of Eratosthenes approach.

Time complexity: O(nlog(log n))
Space complexity: O(n)
 */

import java.util.*;

public class SieveofEratosthenes {
    public static void main (String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number:");
        int limit = scanner.nextInt();

        if(limit < 2) {
            System.out.println(String.format("There are no prime numbers up to %d", limit));
            return;
        }

        SieveofEratosthenes Sieve = new SieveofEratosthenes();
        System.out.println(String.format("Prime numbers up to %d are:", limit));
        boolean[] isPrime = Sieve.getPrimes(limit);
        Sieve.printPrimes(isPrime);
    }

    // Function to get the prime numbers up to the limit.
    public boolean[] getPrimes(int limit) {
        boolean[] isPrime = new boolean[limit + 1];

        // Set all the values from 2 to max as primes.
        for(int i = 2; i <= limit; i++) {
            isPrime[i] = true;
        }

        for(int i = 2; i*i <= limit; i++) {

            // If a value is already set as prime,
            // mark its multiples as non-primes (composites).
            if(isPrime[i]) {
                for(int j = i*2; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    // Function to print the obtained prime numbers.
    public void printPrimes(boolean[] isPrime) {
        for(int i = 2; i < isPrime.length; i++) {
            if(isPrime[i]) {
                System.out.println(i);
            }
        }
    }
}

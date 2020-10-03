/*
This is a Java program to find prime numbers up to a limit
using the Sieve of Eratosthenes approach.
 */
import java.util.*;

public class SieveofEratosthenes {
    public static void main (String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a 32-bit integer.");
        int limit = scanner.nextInt();

        if(limit < 2) {
            System.out.println(String.format("There are no prime numbers less than or equal to %d", limit));
            return;
        }
        if(limit > Integer.MAX_VALUE) {
            System.out.println("Please enter a 32-bit integer.");
            return;
        }

        System.out.println(String.format("Prime numbers in the range 2 to %d are:", limit));
        boolean[] isPrime = getPrimes(limit);
        print(isPrime);
    }

    // Function to get the prime numbers under the limit.
    public static boolean[] getPrimes(int limit) {
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
    public static void print(boolean[] isPrime) {
        for(int i = 2; i < isPrime.length; i++) {
            if(isPrime[i]) {
                System.out.println(i);
            }
        }
    }
}

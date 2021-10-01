using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class SieveOfEratosthenes
{
    // Implementation using the Sieve of Eratosthenes algorithm
    private static int[] GetAllPrimesUpTo(int num) // Includes num
    {
        if (num < 2)
        {
            return new int[0];
        }

        BitArray primes = new BitArray(num + 1);
        primes[2] = true;
        for (int i = 3; i < num; i += 2)
        {
            primes[i] = true;
        }

        for (int i = 0; i * i < num; i++)
        {
            if (primes[i])
            {
                for (int primeMultiple = i * i; primeMultiple < num; primeMultiple += i)
                {
                    primes[primeMultiple] = false;
                }
            }
        }
        
        List<int> primesList = new List<int>();
        for (int i = 0; i < primes.Length; i++)
        {
            if (primes[i])
            {
                primesList.Add(i);
            }
        }

        return primesList.ToArray();
    }

    static void Main(string[] args)
    {
        // Test Cases:
        // Small Number
        // 3
        // 2
        // 1
        // 0
        // Negative Number
        // Large Number
        int[] primes = GetAllPrimesUpTo(100).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 25

        primes = GetAllPrimesUpTo(3).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 1

        primes = GetAllPrimesUpTo(2).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 1

        primes = GetAllPrimesUpTo(1).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 0

        primes = GetAllPrimesUpTo(0).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 0

        primes = GetAllPrimesUpTo(-100).ToArray();
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 0

        primes = GetAllPrimesUpTo(1000000000).ToArray(); // 1 Billion
        Console.WriteLine($"Primes Found: {primes.Length}"); // Primes Found: 50847534

        Console.ReadLine();
    }
}

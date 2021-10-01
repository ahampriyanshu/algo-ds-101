using System;
using System.Collections.Generic;
//Two numbers are amicable if the first is equal to the sum of divisors of the second, 
//and if the second number is equal to the sum of divisors of the first.

public class AmicableNumbersCS {
    public bool AreAmicable(int x, int y) 
    {
        if (EqualsDivisorsOf(x, y) && EqualsDivisorsOf(y, x))
        {
            return true;
        }
        
        return false;
    }
    
    private bool EqualsDivisorsOf(int x, int y)
    {
        int sumOfDivisors = 0;
        
        foreach(int divisor in GetDivisors(y))
        {
            sumOfDivisors += divisor;
        }
        
        if (x == sumOfDivisors)
        {
            return true;
        }
        
        return false;
    }
    
    //https://codereview.stackexchange.com/a/237442
    private int[] GetDivisors(int n)
        {
            if (n <= 0)
            {
                return null;
            }
            List<int> divisors = new List<int>();
            for (int i = 1; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    divisors.Add(i);
                    if (i != n / i)
                    {
                        divisors.Add(n / i);
                    }
                }
            }
            divisors.Remove(n);
            divisors.Sort();
            return divisors.ToArray();
        }
    
}
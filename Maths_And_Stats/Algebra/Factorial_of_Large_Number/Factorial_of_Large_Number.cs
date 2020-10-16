using System;
using System.Collections.Generic;

public class Factorial_of_Large_Number
{
    private static List<int> resultDigits;

    public static void Main(string[] args)
    {
        resultDigits = null;

        Console.Write("Enter a number to find its factorial: ");
        int number = Convert.ToInt32(Console.ReadLine());

        FindFactorial(number);

        Console.WriteLine("The factorial value is: ");
        DisplayDigits();
        
        resultDigits = null;
    }

    // initializes resultDigits list with one element, 1
    // multiplies factors 2, 3, ..., n-1, n
    static void FindFactorial(int n)
    {
        resultDigits = new List<int>();
        resultDigits.Add(1);
        for (int factor = 2; factor <= n; ++factor)
        {
            DigitWiseMultiply(factor);
        }
    }

    // multiplies factor to list treating each element as digit
    // this accounts for carry as well
    static void DigitWiseMultiply(int factor)
    {
        int carry = 0;
        for (int i = resultDigits.Count - 1; i >= 0; --i)
        {
            int temp = resultDigits[i] * factor + carry;
            resultDigits[i] = temp % 10;
            carry = temp / 10;
        }

        // inserts leftover carry to the start of list
        while (carry > 0)
        {
            resultDigits.Insert(0, carry % 10);
            carry /= 10;
        }
    }

    // loops through resultDigits and prints it
    static void DisplayDigits()
    {
        for (int i = 0; i < resultDigits.Count; ++i)
        {
            Console.Write(resultDigits[i]);
        }
    }
}

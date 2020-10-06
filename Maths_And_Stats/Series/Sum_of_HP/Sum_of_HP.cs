/***

About the approach:
	->No particular formula used
		. 1/a is  reciprocal of first term
		. d is common difference for reciprocal
		. n is number of terms
		of the harmonic sequence
	->sum of all terms is found generating each term and adding them
	->Time Complexity: O(n) where n is number of terms in the Harmonic sequence
	->Space Complexity: O(1)
	->It is considered that a,d and n are given by the user and sum is within double datatype limits

***/
using System.IO;
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter the reciprocal of first term in the Harmonic Sequence:");
        double firstTerm = Convert.ToDouble(Console.ReadLine());
        
        Console.WriteLine("Enter the common difference of reciprocal of terms in the Harmonic Sequence:");
        double commonDiff = Convert.ToDouble(Console.ReadLine());
        
        Console.WriteLine("Enter the number of terms in the Harmonic Sequence:");
        int numTerms = Convert.ToInt32(Console.ReadLine());
        
        double term = 1.0 / (firstTerm * 1.0);
        double sum = 0;
        
        if(firstTerm == 0 || numTerms < 0)
        {
            Console.WriteLine("Not possible to find sum of terms in the Harmonic Sequence for the given input");
            return;
        }
        
        for(int i = 1;i <= numTerms;i++)
        {
            sum += term;
            //1.0 is multiplied in denominator to ensure it doesn't get implicitly converted to int
            term = 1.0 / (firstTerm + (i * commonDiff)) * 1.0 ;
        }
        Console.WriteLine("The sum of terms in the Harmonic Sequence are :" + sum);
        
        
        
        
    }
}
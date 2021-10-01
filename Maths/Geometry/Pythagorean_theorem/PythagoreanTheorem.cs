using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class PythagoreanTheorem
{
    // Derived from the Pythagorean Theorem
    // a^2 + b^2 = c^2 in reference to a right triangle's sides a, b, and hypotenuse c
    
    // c = sqrt(a^2 + b^2)
    private static double GetHypotenuse(float a, float b)
    {
        return Math.Sqrt(a * a + b * b);
    }

    // a = sqrt(c^2 - b^2)
    private static double GetSideA(float b, float c)
    {
        return Math.Sqrt(c * c - b * b);
    }

    // b = sqrt(c^2 - a^2)
    private static double GetSideB(float a, float c)
    {
        return Math.Sqrt(c * c - a * a);
    }

    private static bool IsRightAngled(float a, float b, float c)
    {
        return GetHypotenuse(a, b) == c;
    }

    static void Main(string[] args)
    {
        Console.WriteLine(GetHypotenuse(3, 4));
        Console.WriteLine(GetSideA(4, 5));
        Console.WriteLine(GetSideB(3, 5));
        Console.WriteLine(IsRightAngled(3, 4, 5));
        Console.WriteLine(IsRightAngled(3.5f, 4, 5));
        Console.ReadLine();
    }
}

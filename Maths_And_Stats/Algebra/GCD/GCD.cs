using System;
public class Program
{
    static int GCD(int num1, int num2)
    {
        int Remainder;
 
        while (num2 != 0)
        {
            Remainder = num1 % num2;
            num1 = num2;
            num2 = Remainder;
        }
 
        return num1;
    }
 
    static int Main(string[] args)
    {
        int x, y;
        Console.Write("Enter the First Number : ");
        x = int.Parse(Console.ReadLine());
        Console.Write("Enter the Second Number : ");
        y = int.Parse(Console.ReadLine());
        Console.Write("\nThe Greatest Common Divisor of ");
        Console.WriteLine("{0} and {1} is {2}", x, y, GCD(x, y));
        Console.ReadLine();
        return 0;
    }
}
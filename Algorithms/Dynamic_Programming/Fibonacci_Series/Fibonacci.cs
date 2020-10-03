using System;

namespace Fibonacci
{
    public class Program
    {
       public static void Main(string[] args)
        {
            int n;

            Console.Write("Enter the number of terms: ");
            n  = Convert.ToInt32(Console.ReadLine());
            fibonacci(n);

        }

        public static void fibonacci(int n)
        {
            long a = 0;
            long b = 1;

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(b);
                b += a;
                a = b - a;
            }
        }
    }
}

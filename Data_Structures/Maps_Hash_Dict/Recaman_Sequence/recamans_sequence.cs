sing System;
using System.Collections.Generic;


class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("How many numbers do you want to write out?");
        int count = int.Parse(Console.ReadLine());
        List<long> numbers = new List<long>(); 
        numbers.Add(0);
        long last = numbers[0];
        Console.WriteLine(numbers[0]);
        for (int i = 1; i < count; i++)
        {
            if (last - i > 0 && !numbers.Contains(last - i)) 
            {
                numbers.Add(last - i);
                Console.WriteLine(numbers[i]);
                last = numbers[i];
            } else
            {
                numbers.Add(last + i);
                Console.WriteLine(numbers[i]);
                last = numbers[i];
            }
        }
        Console.ReadLine(); // otherwise the console closes
    }
}

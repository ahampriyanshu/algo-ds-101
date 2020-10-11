using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("How many Lucas numbers do you want to write out?");
        int count = int.Parse(Console.ReadLine());
        ulong first = 2;
        ulong second = 1;
        Console.WriteLine(first);
        Console.WriteLine(second);
        ulong number;
        for (int i = 0; i < count - 2; i++)
        {
            number = first + second;
            first = second;
            second = number;
            Console.WriteLine(number);
        }
        Console.ReadLine(); // otherwise the console closes
    }
}

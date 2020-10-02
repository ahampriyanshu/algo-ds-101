using System.IO;
using System;
using System.Linq;
class meanOfGivenNumbers
{
    static void Main()
    {
        var arr = new int[] { 10, 17, 25, 30, 40, 55, 60, 70 };
        double avg = Queryable.Average(arr.AsQueryable());
        Console.WriteLine("Average = " + avg);
    }
}
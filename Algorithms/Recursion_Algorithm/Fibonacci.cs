using System;
using System.Text;

public static class Fibonacci {

    //The Fibonacci Sequence is described as a sequence of numbers in which each number is the sum of the two preceding ones, starting from 0 and 1
    //Creating the sequence 0, 1, 1, 2, 3, 5, 8, 12, ...
    //The following method shows how recursion can be used to calculate the value of any given index in the Fibonacci Sequence, 
    //with indexes 0 and 1 used as termination condition
    public static int GetValue(int index) {
        if (index <= 0)
            return 0;

        if (index == 1) 
            return 1;

        return GetValue(index-1) + GetValue(index-2);
    }
}


//use dotnet-script to test this
Console.WriteLine("Please enter the index to be computed");
var input = Console.ReadLine();
var index = 0;
while(!Int32.TryParse(input, out index)) {
    Console.WriteLine("Please enter the index to be computed");
    input = Console.ReadLine();
}
var fibonacciValue = Fibonacci.GetValue(index);
Console.WriteLine($"The value for index {index} is  {fibonacciValue}");

    
using System;

class Program
{
    /// <summary>
    /// Calculates the compound interest for the given values.
    /// </summary>
    private static double CalculateCompoundInterest(double initialAmount, double interestRate, int totalYears, int compundFrequency)
    {
        return (initialAmount * Math.Pow((1 + (interestRate / compundFrequency)), (compundFrequency * totalYears)));
    }

    /// <summary>
    /// Main application function.
    /// </summary>
    static void Main()
    {
        double initialAmount, interestRate;
        int totalYears, compundFrequency;
        string userInput;
        
        Console.WriteLine("Enter the initial amount:");
        userInput = Console.ReadLine();
        
        if ((double.TryParse(userInput, out initialAmount) == false)) { Program.ExitAfterInvalidInput(); }
        
        Console.WriteLine("Enter the annual interest rate:");
        userInput = Console.ReadLine();
        
        if ((double.TryParse(userInput, out interestRate) == false)) { Program.ExitAfterInvalidInput(); }
        
        Console.WriteLine("Enter the number of years:");
        userInput = Console.ReadLine();
        
        if ((int.TryParse(userInput, out totalYears) == false)) { Program.ExitAfterInvalidInput(); }
        
        Console.WriteLine("Enter the times per year that interest will be compounded:");
        userInput = Console.ReadLine();
        
        if ((int.TryParse(userInput, out compundFrequency) == false)) { Program.ExitAfterInvalidInput(); }
        
        double totalAmount = Program.CalculateCompoundInterest(initialAmount, interestRate, totalYears, compundFrequency);
        string yearText    = (totalYears > 1 ? "years" : "year"); 
        
        Console.WriteLine();
        Console.WriteLine(string.Format("In {0} {1} the total amount will be {2:#0.000}.", totalYears, yearText, totalAmount));
    }
    
    /// <summary>
    /// Informs the user that an invalid value has been entered and exits the program.
    /// </summary>
    private static void ExitAfterInvalidInput()
    {
        Console.WriteLine("You've entered an invalid value. Exiting...");
        Environment.Exit(1);
    }
}

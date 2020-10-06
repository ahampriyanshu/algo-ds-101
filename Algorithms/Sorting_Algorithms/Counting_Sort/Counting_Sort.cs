using System;

class Program
{
    /// <summary>
    /// Sorts the integers in the given array using the Counting SOrt algorithm.
    /// </summary>
    public static int[] CountingSort(int[] arrayToSort)
    {
        int[] sortedArray = new int[arrayToSort.Length];
        
        int minimumValue = arrayToSort[0];
        int maximumValue = arrayToSort[0];

        for (int i = 1; i < arrayToSort.Length; i++)
        {
            if (arrayToSort[i] < minimumValue)
            {
                minimumValue = arrayToSort[i];
            }
            else if (arrayToSort[i] > maximumValue)
            {
                maximumValue = arrayToSort[i];
            }
        }

        int[] counts = new int[((maximumValue - minimumValue) + 1)];

        for (int i = 0; i < arrayToSort.Length; i++)
        {
            counts[(arrayToSort[i] - minimumValue)] += 1;
        }

        counts[0] -= 1;

        for (int i = 1; i < counts.Length; i++)
        {
            counts[i] = (counts[i] + counts[(i - 1)]);
        }

        for (int i = arrayToSort.Length - 1; i > -1; i--)
        {
            sortedArray[(counts[(arrayToSort[i] - minimumValue)]--)] = arrayToSort[i];
        }
     
        return sortedArray;
    }

    /// <summary>
    /// Main application function.
    /// </summary>
    static void Main()
    {
        int[] arrayToSort;
        string userInput;
        
        Console.WriteLine("Enter the integers that you want to sort as a comma delimited string:");
        userInput = Console.ReadLine();
        
        string[] splittedItems = userInput.Split(new string[] { " ", ",", ";", "|" }, StringSplitOptions.RemoveEmptyEntries);

        if (splittedItems.Length == 0) { Program.ExitAfterInvalidInput(); }
        
        arrayToSort = new int[splittedItems.Length];

        for (int i = 0; i < splittedItems.Length; i++)
        {
            int parsedInteger;

            if (int.TryParse(splittedItems[i], out parsedInteger) == false) { Program.ExitAfterInvalidInput(); }

            arrayToSort[i] = parsedInteger;
        }

        int[] sortedArray = Program.CountingSort(arrayToSort);
        
        Console.WriteLine();
        Console.WriteLine(string.Format("Unsorted : {0}", string.Join(", ", userInput)));
        Console.WriteLine(string.Format("Sorted   : {0}", string.Join(", ", sortedArray)));
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

using System;
using System.Collections.Generic;
using System.Linq;

//A Markov Matrix  is a matrix used to describe the transitions of a Markov chain.
//Each of its entries is a nonnegative real number representing a probability between 0 and 1.
//There are three possible types of the Markov Matrix:
//A right stochastic matrix is a matrix with each row summing to 1.
//A left stochastic matrix is a matrix with each column summing to 1.
//A doubly stochastic matrix is a matrix with each row and column summing to 1.

//NOTE: This solution will iterate the whole matrix three times. This can be terribly inefficient for large datasets.
//There are ways to solve this with only one iteration over the matrix, but for the sake of better readability
//this example is not optimized in that way.

public static class MarkovMatrix {
    public static MatrixType Validate(decimal[,] matrix)
    {
        //At first, we check if any element is outside the defined range. If so, the input is not a Markov Matrix
        if (ContainsInvalidElements(matrix))
            return MatrixType.NotAMarkovMatrix;
        
        //Then we first check each row sum
        var isRight = IsRightStochastic(matrix);
        //Then we check each column sum
        var isLeft = IsLeftStochastic(matrix);
        
        //Depending on the results of each check, we return the corresponding result
        var result = (isLeft, isRight);
        switch (result)
        {
            case (true, true):
                return MatrixType.DoublyStochasticMatrix;
            case (true, false):
                return MatrixType.LeftStochasticMatrix;
            case (false, true):
                return MatrixType.RightStochasticMatrix;
            case (false, false):
                return MatrixType.NotAMarkovMatrix;
        }
    }

    private static bool ContainsInvalidElements(decimal[,] matrix)
    {
        //check if any element of the matrix is either below 0 or above 1
        return matrix.Cast<decimal>().Any(element => element > 1 || element < 0);
    }
    private static bool IsLeftStochastic(decimal[,] matrix)
    {
        //a left stochastic matrix has a sum of 1 for each column
        //to check this, we iterate through each column and check the sum of it's elements
        var columnCount = matrix.GetLength(1);
        
        for (var i = 0; i < columnCount; i++)
        {
            if (GetColumn(matrix, i).Sum() != 1) return false;
        }

        return true;
    }
    
    private static bool IsRightStochastic(decimal[,] matrix)
    {
        //a right stochastic matrix has a sum of 1 for each row
        //to check this, we iterate through each row and check the sum of it's elements
        var rowCount = matrix.GetLength(0);

        for (var i = 0; i < rowCount; i++)
        {
            if (GetRow(matrix, i).Sum() != 1) return false;
        }

        return true;
    }

    private static IEnumerable<decimal> GetRow(decimal[,] matrix, int rowIndex)
    {
        //Get a certain row inside the matrix: iterate through all columns with fixed row index
        var columnCount = matrix.GetLength(1);
        
        for (var i = 0; i < columnCount; i++)
        {
            yield return matrix[rowIndex, i];
        }
    }
    
    private static IEnumerable<decimal> GetColumn(decimal[,] matrix, int columnIndex)
    {
        //Get a certain column inside the matrix: iterate through all rows with fixed column index
        var rowCount = matrix.GetLength(0);
        
        for (var i = 0; i < rowCount; i++)
        {
            yield return matrix[i, columnIndex];
        }
    }
}

public enum MatrixType
{
    NotAMarkovMatrix = 0,
    RightStochasticMatrix = 1,
    LeftStochasticMatrix = 2,
    DoublyStochasticMatrix = 3
}

    
//use dotnet-script to run this code
Console.WriteLine("Enter Matrix to check, line by line");
Console.WriteLine("Columns are separated by single space character");
Console.WriteLine("Empty string ends input and starts validation");

var input = Console.ReadLine();
var numbersList = input.Split(' ').Select(i => decimal.Parse(i)).ToList();
var columns = numbersList.Count();
var rows = 1;

input = Console.ReadLine();
while (!string.IsNullOrWhiteSpace(input))
{
    var row = input.Split(' ').Select(i => decimal.Parse(i)).ToList();
    if (row.Count == columns)
    {
        numbersList.AddRange(row);
        rows++;
    }
    else
    {
        Console.WriteLine("All rows must have the same amount of columns");
    }
    input = Console.ReadLine();
};

var matrix = ConvertToSquareArray(rows, columns, numbersList);

Console.WriteLine(MarkovMatrix.Validate(matrix));

private static decimal[,] ConvertToSquareArray(int rows, int columns, List<decimal> numbers)
{
    var index = 0;
    var rowIndex = 0;
    var colIndex = 0;
    var matrix = new decimal[rows, columns];
    foreach (var number in numbers)
    {
        matrix.SetValue(number, rowIndex, colIndex);
        index++;
        rowIndex += 1;
        rowIndex %= rows;
        colIndex += 1;
        colIndex %= columns;
    }

    return matrix;
}
    
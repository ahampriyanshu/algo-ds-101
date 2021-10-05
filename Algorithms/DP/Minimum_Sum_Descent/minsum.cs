using System;
using System.Collections.Generic;

// C# program of min sum path in a triangle
namespace Minimum_sum_descent_in_C
{
  class Program
  {
    static void Main(string[] args)
    {
      List<List<int>> A = new List<List<int>>();
      A.Add(new List<int> { 2 });
      A.Add(new List<int> { 3, 9 });
      A.Add(new List<int> { 1, 6, 7 });
      Console.WriteLine(Triangle.minSumPath(ref A));
    }
  }

  class Triangle
  {
    // Function to find minimum sum for a path
    public static int minSumPath(ref List<List<int>> A)
    {
      // Storing the result in a array and simultaneously updating the result
      int[] memo = new int[A.Count];
      int n = A.Count - 1;

      // For the bottom row
      for (int i = 0; i < A[n].Count; i++)
        memo[i] = A[n][i];

      // Calculation of the remaining rows
      for (int i = A.Count - 2; i >= 0; i--)
        for (int j = 0; j < A[i + 1].Count - 1; j++)
          memo[j] = A[i][j] +
                    (int)Math.Min(memo[j],
                             memo[j + 1]);

      // Return the top element
      return memo[0];
    }
  }
}

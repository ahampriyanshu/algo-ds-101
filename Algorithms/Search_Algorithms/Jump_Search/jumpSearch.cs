//Jump Search implementation in C#.

using System;

class MainClass {
  public static void Main (string[] args) {

    double[] arr = {0, 1, 2, 4, 9, 16, 25, 36, 64, 81, 100, 121, 144, 189, 400, 625};
    double n = arr.Length;
    double x = 144;


    double step = Math.Sqrt(n);
    step = Math.Truncate(step);
    double j = n-step-1;
    for (double i=0; i<n; i=i+step)
    {
        if(arr[(int)i]>x)
        {
          j = i - step;
          break;
        }
    }
    
    double ub = j + step + 1;
    for ( ; j<ub; j++)
    {
      if(arr[(int)j]==x)
      {
        Console.WriteLine("Number found at index "+(int)j);
      }
    }

  }
}

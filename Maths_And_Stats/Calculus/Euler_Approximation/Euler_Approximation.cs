using System;

class Program
{
    /// <summary>
    /// Main application function.
    /// </summary>
    static void Main()
    {
        // approximates f(2) given dy/dx = x + y; y(-1) = 1
        //  using 6 equal subdivisions
        Console.WriteLine(Approximate(-1, 1, 2, 6));
    }
    /// <summary>
    /// Uses Euler's method to approximate a point.
    /// </summary>
    /// <param name="xInitial">initial condition for the X value</param>
    /// <param name="yInitial">initial condition for the Y value</param>
    /// <param name="xApprox">xApprox value to approximate</param>
    /// <param name="steps">steps number of steps to use for the approximation. Used to determine step size.</param>
    /// <returns>approximation of f(xApprox)</returns>
    public static double Approximate(double xInitial, double yInitial, double xApprox, int steps)
    {
        // find step size
        // (b - a) / n
        double stepSize = (xApprox - xInitial) / (double)steps;

        // check track of the X and Y coordinates
        double prevX = xInitial;
        double prevY = yInitial;

        // iterate until we meet our end coordinate
        for (int i = 0; i < steps; i++)
        {
            // apply Euler's method
            // f(x) = f(prevY) + stepSize * dy/dx(prevX, prevY)
            prevY += stepSize * Differential(prevX, prevY);
            prevX += stepSize;
        }

        return prevY;
    }
    /// <summary>
    /// Represents dy/dx. Change this function to your desired differential equation
    /// </summary>
    /// <param name="x">X coordinate value</param>
    /// <param name="y">Y coordinate value</param>
    /// <returns>dy/dx evaluated at the coordinate (x, y)</returns>
    private static double Differential(double x, double y)
    {
        return (x + y);
    }
}


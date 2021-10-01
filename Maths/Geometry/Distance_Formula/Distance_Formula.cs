using System;

internal struct Point
{
    public float x;
    public float y;

    public Point(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public override string ToString()
    {
        return $"({x},{y})";
    }
}

public class Distance_Formula
{
    public static void Main(string[] args)
    {
        string[] input = new string[2];

        // Get coordinates of point A from stdin
        Console.WriteLine("Enter coordinates of point A: ");
        Console.Write("x: ");
        input[0] = Console.ReadLine();
        Console.Write("y: ");
        input[1] = Console.ReadLine();
        Point pointA = new Point(
            x: Convert.ToSingle(input[0]),
            y: Convert.ToSingle(input[1])
        );

        // Get coordinates of point B from stdin
        Console.WriteLine("Enter coordinates of point B: ");
        Console.Write("x: ");
        input[0] = Console.ReadLine();
        Console.Write("y: ");
        input[1] = Console.ReadLine();
        Point pointB = new Point(
            x: Convert.ToSingle(input[0]),
            y: Convert.ToSingle(input[1])
        );

        // calculate distance
        double distance = Math.Sqrt(
            (pointB.x - pointA.x) * (pointB.x - pointA.x) +
            (pointB.y - pointA.y) * (pointB.y - pointA.y));

        // output to stdout
        Console.WriteLine($"The distance between {pointA} and {pointB} is {distance}");
    }
}

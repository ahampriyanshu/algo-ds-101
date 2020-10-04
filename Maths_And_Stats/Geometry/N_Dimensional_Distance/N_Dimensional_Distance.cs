using System;

public class Program
{

    static float Distance(float[] positionA, float[] positionB)
    {
        if (positionA.Length != positionB.Length)
        {
            throw new ArgumentException("Both positions must have the same dimensions.");
        }

        float totalSqrDifference = 0;

        for (int i = 0; i < positionA.Length; i++)
        {
            float difference = (positionB[i] - positionA[i]);
            float sqrDifference = difference * difference;
            totalSqrDifference += sqrDifference;
        }

        return MathF.Sqrt(totalSqrDifference);
    }

    public static void Main(string[] args)
    {
        float[] positionA = { 0.0f, 1.0f, 3.0f };
        float[] positionB = { 3.0f, 2.0f, 4.0f };

        float distance = Distance(positionA, positionB);

        Console.WriteLine($"The distance between position A and position B is {distance}");
    }

}
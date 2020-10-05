using System;

internal interface IFunction
{
    float CalculateFx(float x);
}

internal class XPowerN : IFunction
{
    private float n = 0;

    public XPowerN(float n)
    {
        this.n = n;
    }

    public float CalculateFx(float x)
    {
        return MathF.Pow(x, n);
    }

    public override string ToString()
    {
        return $"y = x^{n}";
    }
}

internal class AsinNX : IFunction
{
    private float a = 0;
    private float n = 0;

    public AsinNX(float a, float n)
    {
        this.a = a;
        this.n = n;
    }

    public float CalculateFx(float x)
    {
        return a * MathF.Sin(n * x);
    }

    public override string ToString()
    {
        return $"y = {a} * sin {n}x";
    }
}

internal class AcosNX : IFunction
{
    private float a = 0;
    private float n = 0;

    public AcosNX(float a, float n)
    {
        this.a = a;
        this.n = n;
    }

    public float CalculateFx(float x)
    {
        return a * MathF.Cos(n * x);
    }

    public override string ToString()
    {
        return $"y = {a} * cos {n}x";
    }
}

internal class AtanNX : IFunction
{
    private float a = 0;
    private float n = 0;

    public AtanNX(float a, float n)
    {
        this.a = a;
        this.n = n;
    }

    public float CalculateFx(float x)
    {
        return a * MathF.Tan(n * x);
    }

    public override string ToString()
    {
        return $"y = {a} * tan {n}x";
    }
}

public class Riemann_Sum
{
    public static void Main(string[] args)
    {
        do
        {
            IFunction function;
            Console.Clear();
            Console.WriteLine("Select the desired function: ");
            Console.WriteLine("1. y = x^n");
            Console.WriteLine("2. y = A * sin nx");
            Console.WriteLine("3. y = A * cos nx");
            Console.WriteLine("4. y = A * tan nx");

            Console.Write("\nPick a function: ");
            float tempA;
            switch (Convert.ToInt32(Console.ReadLine()))
            {
                // TODO: finish
                case 1:
                    Console.Write("Enter a value for n: ");
                    function = new XPowerN(Convert.ToSingle(Console.ReadLine()));
                    break;
                case 2:
                    Console.Write("Enter a value for A: ");
                    tempA = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter a value for n: ");
                    function = new AsinNX(tempA, Convert.ToSingle(Console.ReadLine()));
                    break;
                case 3:
                    Console.Write("Enter a value for A: ");
                    tempA = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter a value for n: ");
                    function = new AcosNX(tempA, Convert.ToSingle(Console.ReadLine()));
                    break;
                case 4:
                    Console.Write("Enter a value for A: ");
                    tempA = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter a value for n: ");
                    function = new AtanNX(tempA, Convert.ToSingle(Console.ReadLine()));
                    break;
                default:
                    continue;
            }

            // Enter bounds of the evaluation. Note that lower must be less than upper
            Console.Write("Enter the lower limit of the evaluation: ");
            float lower = Convert.ToSingle(Console.ReadLine());

            Console.Write("Enter the upper limit of the evaluation: ");
            float upper = Convert.ToSingle(Console.ReadLine());

            // must be non-zero
            Console.Write("Enter the resolution of the Riemann approximation: ");
            uint resolution = Convert.ToUInt32(Console.ReadLine());

            Console.WriteLine();
            EvaluateRiemannSumLeft(function, lower, upper, resolution);
            EvaluateRiemannSumRight(function, lower, upper, resolution);
            EvaluateRiemannSumTrapezoid(function, lower, upper, resolution);
            break;
        } while (true);
    }

    private static void EvaluateRiemannSumLeft(
        IFunction function,
        in float lowerLimit,
        in float upperLimit,
        in uint resolution)
    {
        float riemannSum = 0f;
        float xIncrement = (upperLimit - lowerLimit) / resolution;
        for (int i = 0; i < resolution; ++i)
        {
            float x = lowerLimit + xIncrement * i;
            float height = function.CalculateFx(x);
            riemannSum += xIncrement * height;
        }

        Console.WriteLine($"The Left  Riemann sum of {function} between {lowerLimit} and {upperLimit} is {riemannSum}.");
    }

    private static void EvaluateRiemannSumRight(
        IFunction function,
        in float lowerLimit,
        in float upperLimit,
        in uint resolution)
    {
        float riemannSum = 0f;
        float xIncrement = (upperLimit - lowerLimit) / resolution;
        for (int i = 1; i <= resolution; ++i)
        {
            float x = lowerLimit + xIncrement * i;
            float height = function.CalculateFx(x);
            riemannSum += xIncrement * height;
        }
        Console.WriteLine($"The Right Riemann sum of {function} between {lowerLimit} and {upperLimit} is {riemannSum}.");
    }

    private static void EvaluateRiemannSumTrapezoid(
        IFunction function,
        in float lowerLimit,
        in float upperLimit,
        in uint resolution)
    {
        float riemannSum = 0f;
        float xIncrement = (upperLimit - lowerLimit) / resolution;
        for (int i = 0; i < resolution; ++i)
        {
            float x = lowerLimit + xIncrement * i;
            float leftValue = function.CalculateFx(x);
            float rightValue = function.CalculateFx(x + xIncrement);

            if (leftValue < rightValue)    // leftValue is lower, section is increasing
            {
                // adding area of smallest rect
                riemannSum += xIncrement * leftValue;

                // adding triangle area
                riemannSum += 0.5f * xIncrement * (rightValue - leftValue);
            }
            else                           // rightValue is lower, section is decreasing
            {
                // adding area of smallest rect
                riemannSum += xIncrement * rightValue;

                // adding triangle area
                riemannSum += xIncrement * (leftValue - rightValue);
            }


        }

        Console.WriteLine($"The Trapezoid Riemann sum of {function} between {lowerLimit} and {upperLimit} is {riemannSum}.");
    }
}

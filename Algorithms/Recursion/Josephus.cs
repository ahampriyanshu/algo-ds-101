using System;

class TEMP {

	static int josephus(int n, int k)
	{
		if (n == 1)
			return 1;
		else

			return (josephus(n - 1, k) + k - 1) % n + 1;
	}


	public static void Main()
	{
		int n ;
		int k ;
        n= Convert.ToInt32(Console.ReadLine());
        k= Convert.ToInt32(Console.ReadLine());
		Console.WriteLine("The chosen "
                          + "place is " + josephus(n, k));
	}
}

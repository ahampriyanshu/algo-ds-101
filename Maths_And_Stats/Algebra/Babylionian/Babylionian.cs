// C# Porgram for Babylonian 
// method of square root 
// Contributed By - Ayush Sharma (belphegor-s)
using System; 

class SQRT { 

	// Returns the square root of n. 
	// Note that the function 
	static float squareRoot(float n) 
	{ 

		// We are using n itself as 
		// initial approximation This 
		// can definitely be improved 
		float x = n; 
		float y = 1; 

		// e decides the 
		// accuracy level 
		double e = 0.000001; 
		while (x - y > e) { 
			x = (x + y) / 2; 
			y = n / x; 
		} 
		return x; 
	} 

	 
	public static void Main() 
	{ 
		int n = Console.ReadLine();
		Console.Write("Square root of "
					+ n + " is " + squareRoot(n)); 
	} 
} 



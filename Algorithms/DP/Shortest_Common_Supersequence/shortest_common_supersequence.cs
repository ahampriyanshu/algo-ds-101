using System; 

class SCS
{ 


	static String printShortestSuperSeq(String X, String Y) 
	{ 
		int m = X.Length; 
		int n = Y.Length; 

		int [,]dp = new int[m + 1, n + 1]; 
		int i, j; 
		
	 
		for (i = 0; i <= m; i++) 
		{ 
			for (j = 0; j <= n; j++) 
			{ 
				
				 
				if (i == 0) 
				{ 
					dp[i, j] = j; 
				} 
				else if (j == 0) 
				{ 
					dp[i, j] = i; 
				} 
				else if (X[i - 1] == Y[j - 1]) 
				{ 
					dp[i, j] = 1 + dp[i - 1, j - 1]; 
				} 
				else
				{ 
					dp[i, j] = 1 + Math.Min(dp[i - 1, j], dp[i, j - 1]); 
				} 
			} 
		} 

		int index = dp[m, n]; 

		String str = ""; 

		i = m; j = n; 
		while (i > 0 && j > 0) 
		{ 
			if (X[i - 1] == Y[j - 1]) 
			{ 
				str += (X[i - 1]); 
				i--; 
				j--; 
				index--; 
			} 
			
		
			else if (dp[i - 1, j] > dp[i, j - 1]) 
			{
				str += (Y[j - 1]); 
				j--; 
				index--; 
			} 
			else
			{ 
				
				
				str += (X[i - 1]); 

		
				i--; 
				index--; 
			} 
		} 

	 
		while (i > 0) 
		{ 
			str += (X[i - 1]); 
			i--; 
			index--; 
		} 

		
		while (j > 0) 
		{ 
			str += (Y[j - 1]); 
			j--; 
			index--; 
		} 

	
		str = reverse(str); 
		return str; 
	} 

	static String reverse(String input) 
	{ 
		char[] temparray = input.ToCharArray(); 
		int left, right = 0; 
		right = temparray.Length - 1; 

		for (left = 0; left < right; left++, right--) 
		{ 
			char temp = temparray[left]; 
			temparray[left] = temparray[right]; 
			temparray[right] = temp; 
		} 
		return String.Join("",temparray); 
	} 
	
	// code 
	public static void Main(String[] args) 
	{ 
		String X;
		String Y;
		X = Console.ReadLine();
		Y = Console.ReadLine();
		Console.WriteLine(printShortestSuperSeq(X, Y)); 
	} 
} 


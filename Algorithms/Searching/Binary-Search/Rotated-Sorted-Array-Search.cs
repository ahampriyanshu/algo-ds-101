// C# program to find a pair with a given 
// sum in a sorted and rotated array 
// Written By - Ayush Sharma (belphegor-s) 
using System; 

class PairInSortedRotated 
{ 
	// This function returns true if arr[0..n-1] 
	// has a pair with sum equals to x. 
	static bool pairInSortedRotated(int []arr, 
									int n, int x) 
	{ 
		// Find the pivot element 
		int i; 
		for (i = 0; i < n - 1; i++) 
			if (arr[i] > arr[i + 1]) 
				break; 
				
		// l is now index of smallest element		 
		int l = (i + 1) % n; 
		
		// r is now index of largest element				 
		int r = i; 
	
		// Keep moving either l or r till they meet 
		while (l != r) 
		{ 
			// If we find a pair with sum x, we 
			// return true 
			if (arr[l] + arr[r] == x) 
				return true; 
	
			// If current pair sum is less, 
			// move to the higher sum 
			if (arr[l] + arr[r] < x) 
				l = (l + 1) % n; 
			
			// Move to the lower sum side	 
			else
				r = (n + r - 1) % n; 
		} 
		return false; 
	} 

	// Driver Code 
	public static void Main () 
	{ 
		int []arr = {11, 15, 6, 8, 9, 10}; 
		int sum = 16; 
		int n = arr.Length; 
	
		if (pairInSortedRotated(arr, n, sum)) 
			Console.WriteLine("Array has two elements" + 
									" with sum 16"); 
		else
		Console.WriteLine("Array doesn't have two" + 
							" elements with sum 16 "); 
	} 
} 

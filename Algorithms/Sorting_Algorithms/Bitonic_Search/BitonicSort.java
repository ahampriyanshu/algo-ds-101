/* Java program for Bitonic Sort. Size of input should always be a power of 2. */
public class BitonicSort 
{ 
	

	/* Sorts a bitonic sequence recursively in ascending 
	order, if arr = 1, and in descending order otherwise 
	(means arr=0). The sequence to be sorted starts at 
	index position low, the parameter cnt is the number 
	of elements to be sorted.*/
	void merge(int a[], int low, int cnt, int arr) 
	{ 
		if (cnt>1) 
		{ 
			int k = cnt/2; 
			for (int i=low; i<low+k; i++) 
				swap(a,i, i+k, arr); 
			merge(a,low, k, arr); 
			merge(a,low+k, k, arr); 
		} 
	} 
	
	/* The arr indicates the sorting direction, 
	ASCENDING or DESCENDING; if (a[i] > a[j]) agrees 
	with the direction, then a[i] and a[j] are 
	interchanged. */
	void swap(int a[], int i, int j, int arr) 
	{ 
		if ( (a[i] > a[j] && arr == 1) || 
			(a[i] < a[j] && arr == 0)) 
		{ 
			// Swap elements 
			int temp = a[i]; 
			a[i] = a[j]; 
			a[j] = temp; 
		} 
	} 

	/* A bitonic sequence is produced by 
	recursively sorting its two halves in opposite sorting 
	orders, and then calls merge to make them in 
	the same order */
	void bitonicSort(int a[], int low, int cnt, int arr) 
	{ 
		if (cnt>1) 
		{ 
			int k = cnt/2; 

			// sort in ascending order since arr here is 1 
			bitonicSort(a, low, k, 1); 

			// sort in descending order since arr here is 0 
			bitonicSort(a,low+k, k, 0); 

			// Will merge wole sequence in ascending order 
			// since arr=1. 
			merge(a, low, cnt, arr); 
		} 
	} 

	/* bitonicSort is called here for sorting the entire array 
	of length N in ASCENDING order */
	void sort(int a[], int N, int up) 
	{ 
		bitonicSort(a, 0, N, up); 
	} 

	/* A utility function to print array of size n */
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
		System.out.println(); 
	} 

	// Driver method 
	public static void main(String args[]) 
	{ 
		int a[] = {5,7,2,4}; 
		int up = 1; 
		BitonicSort ob = new BitonicSort(); 
		ob.sort(a, a.length,up); 
		System.out.println("\nSorted array"); 
		printArray(a); 
	} 
} 

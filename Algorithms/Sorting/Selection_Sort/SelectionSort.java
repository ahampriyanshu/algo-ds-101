// Java program for implementation of Selection Sort 

class SelectionSort 
{ 
	void sort(int arr[]) 
	{ 
		int n = arr.length; 

		for (int i = 0; i < n-1; i++) 
		{ 
			// Find the minimum element in unsorted array 
			int min_idx = i; 
			for (int j = i+1; j < n; j++) 
				if (arr[j] < arr[min_idx]) 
					min_idx = j; 

			// Swap the found minimum element with the first 
			// element 
			int temp = arr[min_idx]; 
			arr[min_idx] = arr[i]; 
			arr[i] = temp; 
		} 
	} 

	// Prints the array 
	void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 
		SelectionSort obj = new SelectionSort(); 
		int arr[] = {50, 40, 30, 20, 10}; // Default Array
		obj.sort(arr);  // Calling sorting funtion
		obj.printArray(arr); //Printing Array
	} 
} 


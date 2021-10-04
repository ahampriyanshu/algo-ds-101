// Java program for implementation of QuickSort 

class QuickSort 
{ 
	// This function takes last element as pivot.

	int partition(int arr[], int low, int high) 
	{ 
		int pivot = arr[high]; 
		int i = (low-1); // index of smaller element 
		for (int j=low; j<high; j++) 
		{ 
			// If current element is smaller than the pivot 
			if (arr[j] < pivot) 
			{ 
				i++; 

				// swap arr[i] and arr[j] 
				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 
			} 
		} 

		// swap arr[i+1] and arr[high] (or pivot) 
		int temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 

		return i+1; 
	} 


	void sort(int arr[], int low, int high) 
	{ 
		if (low < high) 
		{ 
			// pi is partitioning index, arr[pi] is now at right place.
            
			int pi = partition(arr, low, high); 

			// Recursively sort elements before 
			// partition and after partition 
			sort(arr, low, pi-1); 
			sort(arr, pi+1, high); 
		} 
	} 

	// Function to print array.
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 

	// Driver Code
	public static void main(String args[]) 
	{ 
		int arr[] = {5, 4, 3, 2, 1}; // Default Array 
		int n = arr.length; 

		QuickSort obj = new QuickSort(); 
		obj.sort(arr, 0, n-1);  // Calling sort function

		printArray(arr);  // Call function that print array
	} 
} 


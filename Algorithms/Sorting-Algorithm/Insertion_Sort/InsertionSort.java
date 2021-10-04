// Java program for implementation of Insertion Sort 

class InsertionSort { 
    //  Function to sort the array
	void sort(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i = 1; i < n; ++i) { 
			int key = arr[i]; 
			int j = i - 1; 

			while (j >= 0 && arr[j] > key) { 
				arr[j + 1] = arr[j]; 
				j = j - 1; 
			} 
			arr[j + 1] = key; 
		} 
	} 

	//  Function to print array of size n.
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i = 0; i < n; ++i) 
			System.out.print(arr[i] + " "); 

		System.out.println(); 
	} 

	// Driver method 
	public static void main(String args[]) 
	{ 
		int arr[] = { 5, 4, 3, 2, 1 }; 

		InsertionSort obj = new InsertionSort();  //Creating object of the class
		obj.sort(arr);  // Calling sort function

		printArray(arr); // Call function that print array
	} 
}

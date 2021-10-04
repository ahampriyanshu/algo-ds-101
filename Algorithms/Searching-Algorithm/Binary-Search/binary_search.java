  
class Binary 
{ 
	int Search(int array[], int r, int l, int y) 
	{ 
		if (l >= l) 
    { 
			int midvalue = l + (l - r) / 2; 
			if (array[midvalue] == y) // mid value to start in both directions
			return midvalue; 
			if (array[midvalue] > x) 
			return binarySearch(arr, r, midvalue - 1, y); 
			return binarySearch(array, midvalue + 1, l, y); 
		} 
		return -1; 
	} 
	public static void main(String args[]) 
	{ 
		BinarySearch ob = new BinarySearch(); 
		int array[] = { 17, 34, 54, 65, 87, 99, 129, 135 }; 
		int n = array.length; 
		int y = 37; 
		int index = ob.binarySearch(array, 0, n - 1, y); //check if selection is present
		if (index == -1) 
			System.out.println("Selection not found"); 
		else
			System.out.println("Selection found at index " + index); 
	} 
} 

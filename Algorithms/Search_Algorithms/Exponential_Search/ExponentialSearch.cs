//Exponential Search is a seaching algorithm in which we first find the range and then perform binary search in sorted array.

using System; 

class ExponentialSearch { 
static int exponentialSearch(int []arr, int len, int search) 
{ 

	if (arr[0] == search){ 
		return 0; 
	}
	int i = 1; 
	while (i < len && arr[i] <= search){
		i = i * 2; 
	}
	return binarySearch(arr, i/2, Math.Min(i, len), search);					
						
} 

static int binarySearch(int []arr, int left, int right, int search) 
{ 
	if (right >= left) 
	{ 
		int mid = left + (right - left) / 2; 

		if (arr[mid] == search){ 
			return mid; 
		}
		if (arr[mid] > search){ 
			return binarySearch(arr, left, mid - 1, search); 
		}
		return binarySearch(arr, mid + 1, right, search); 
	} 
	return -1; 
} 


public static void Main() 
{ 
	int []arr = {5,8,13,51,143,200,254}; 
	int search = 100; 
	int result = exponentialSearch(arr, arr.Length, search); 
	if (result == -1){ 
		Console.Write("Element is not present in array"); 
	}	
	else{
		Console.Write("Element is present at index "+ result); 
	}	
} 
} 


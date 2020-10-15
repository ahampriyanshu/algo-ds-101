import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class QuickSort {
	
	private static void swap(Comparable[] arr, int first, int second)
	{	// Swaps the two array elements with indices passed as arguments.
		Comparable temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

	
	private static void quickSort3Way(Comparable[] arr, int low, int high)
	{	/*
			arr: Array to be sorted using the Three Way QuickSort Algorithm
			low: The starting index of a subarray
			high: The ending index of a subarray
		*/
		
		// No partitioning for subarrays of size 1 or below.
		if(high <= low) return;

		// Partitioning item value
		Comparable v = arr[low];
		
		// Three variables lesser, i and greater are used for the corresponding partitions to be made.
		// lesser partition i.e. arr[low .. lesser - 1] denotes the partition with items of value less than the partitioning item v.
		// greater partition i.e arr[greater + 1 .. high] denotes the partition with items of value greater than the partitioning item v.
		// equals partition i.e. arr[lesser .. greater] denotes the partition with items of value equal to the partitioning item v.
		// variable i represents the current element that is to be put into one of the above three partitions.
		int lesser = low, i = low + 1, greater = high;

		while(i <= greater)
		{
			int cmp = arr[i].compareTo(v);
			if(cmp < 0) swap(arr, lesser++, i++);
			else if(cmp > 0) swap(arr, i, greater--);
			else i++;
		}
		quickSort3Way(arr, low, lesser-1);
		quickSort3Way(arr, greater+1, high);
	}
	
	private static void printSortedArray(Comparable[] arr)
	{	// Prints the sorted array as output.
		for(int index=0; index<arr.length; index++)
			System.out.print(arr[index]+" ");
		System.out.println();
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = reader.readLine().split(" "); // String[] used in this implementation. Any data type implementing the Comparable interface can be used in it's place.
		quickSort3Way(arr, 0, arr.length-1); // Sort the input array using the Three Way QuickSort Algorithm.
		printSortedArray(arr); // Print the output as the sorted array.
	}
}

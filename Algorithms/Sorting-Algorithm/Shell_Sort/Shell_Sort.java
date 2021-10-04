import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ShellSort {
	
	private static void shellSort(Comparable[] arr)
	{	//Sort arr[] into increasing order
		int N = arr.length;
		int h = 1;
		while(h < N/3)
			h = 3*h+1; // 1, 4, 13, 40, 121, 364, 1093, ... 
		while(h >= 1)
		{	//h-sort the array
			for(int i=h; i<N; i++)
			{	//Insert arr[i] among arr[i-h], arr[i-2*h], arr[i-3*h]...
				for(int j=i; j>=h && lessThan(arr[j], arr[j-h]); j-=h)
					swap(arr, j, j-h);
			}
			h = h/3;
		}
	}
	
	private static boolean lessThan(Comparable first, Comparable second)
	{
		return first.compareTo(second) < 0; 
	}
	
	private static void swap(Comparable[] arr, int first, int second)
	{	// Swaps two elements in the array.
		Comparable temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}
	
	private static void printSortedArray(Comparable[] arr)
	{	// Print the sorted array as output, on a single line.
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = reader.readLine().split(" "); // String[] used in this implementation. Any data type implementing the Comaprable interface can be used in it's place.
		shellSort(arr); // Sort the array using ShellSort
		printSortedArray(arr); // Print the sorted output
	}
}

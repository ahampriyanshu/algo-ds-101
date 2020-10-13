/*
Input Format: length of the array and contents of the array
Output Format: length of LIS and contents of the LIS
Sample Input and Output
**Sample Input 1:**
Enter the number of elements of the array: 8
Enter the elements of the array: 1 8 5 9 6 2 4 7
The length of LIS is: 4
The LIS is: 1 5 6 7
**Sample Input 2:**
Enter the number of elements of the array: 10
Enter the elements of the array: 1 2 3 6 5 8 9 4 7 6
The length of LIS is: 6
The LIS is: 1 2 3 6 8 9
Graph contains cycle!
*/


import java.util.*; 

class Main
{
	public static void findLIS(int[] arr)
	{
		// LIS.get(i) stores the longest increasing subsequence of subarray
		List<List<Integer>> LIS = new ArrayList<>();
		for (int i = 0; i < arr.length; i++) {
			LIS.add(new ArrayList<>());
		}

		// LIS[0] denotes longest increasing subsequence ending with arr[0]
		LIS.get(0).add(arr[0]);

	
		for (int i = 1; i < arr.length; i++)
		{

			for (int j = 0; j < i; j++)
			{
				// find longest increasing subsequence that ends with arr[j]
				// where arr[j] is less than the current element arr[i]

				if (arr[j] < arr[i] && LIS.get(j).size() > LIS.get(i).size()) {
					LIS.set(i, new ArrayList<>(LIS.get(j)));
				}
			}

			// include arr[i] in LIS.get(i)
			LIS.get(i).add(arr[i]);
		}

		
		int j = 0;
		for (int i = 0; i < arr.length; i++) {
			if (LIS.get(j).size() < LIS.get(i).size()) {
				j = i;
			}
		}
		
        System.out.print("The length of LIS is:" + (LIS.get(j)).size());
		System.out.print("\n"+"The LIS is:" + LIS.get(j));
	}

	public static void main(String[] args)
	{
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of elements of the array:"+"\n");
		int n = sc.nextInt();
	System.out.print("Enter the elements of the array:"+"\n");
        int array[] = new int[n];
        for (int i = 0; i < n; ++i)
        {
            array[i] = sc.nextInt();
        }

		findLIS(array);
		
	}
}

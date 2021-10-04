import java.util.*;
class two_pointer_sorted_array
{
        static  int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i)
		{
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr, Comparator.comparingInt(o -> o[0])); // Sorting arr in increasing/ascending order by their values.
        int left = 0, right = n - 1;
        while (left < right) {
            int sum2 = arr[left][0] + arr[right][0];
            if (sum2 == target)
                return new int[]{arr[left][1], arr[right][1]};
            if (sum2 > target)
                right -= 1; // Try to decrease sum2
            else
                left += 1; // Try to increase sum2
        }
        return new int[]{};
    }

	public static void main(String args[]) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		//Dynamically creating of arrays.
		List<Integer> al = new ArrayList<>();
		for(int i=0;i<4;i++)
	    {
			int x = in.nextInt();
			al.add(x);
		}

		//System.out.println(al);
		//converting it to static array.
		int []nums =new int[al.size()];
		for(int i=0;i<al.size();i++)  // 2 7 11 15
			nums[i]=al.get(i);



		int target = in.nextInt(); // 9
		//Saving the returned array and printing it.
		 int arr[] = twoSum(nums,target);
		 System.out.println(Arrays.toString(arr));  //[0,1] 




	}

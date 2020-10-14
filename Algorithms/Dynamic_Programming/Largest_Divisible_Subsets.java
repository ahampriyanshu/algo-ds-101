import java.util.*; 
  
public class DivSubset { 
  
    public static int[][] dp; 
  
    // Prints largest divisible subset 
    static void findLargest(int[] arr) { 
  
        // array that maintains the maximum index  
        // till which the condition is satisfied 
        int divCount[] = new int[arr.length]; 
          
        // we will always have atleast one  
        // element divisible by itself 
        Arrays.fill(divCount, 1); 
  
        // maintain the index of the last increment 
        int prev[] = new int[arr.length]; 
        Arrays.fill(prev, -1); 
  
        // index at which last increment happened 
        int max_ind = 0; 
  
        for (int i = 1; i < arr.length; i++) { 
            for (int j = 0; j < i; j++) { 
  
                // only increment the maximum index if  
                // this iteration will increase it 
                if (arr[i] % arr[j] == 0 &&  
                    divCount[i] < divCount[j] + 1) { 
                    prev[i] = j; 
                    divCount[i] = divCount[j] + 1; 
  
                } 
  
            } 
        // Update last index of largest subset if size 
        // of current subset is more. 
            if (divCount[i] > divCount[max_ind]) 
                max_ind = i; 
        } 
  
        // Print result 
        int k = max_ind; 
        while (k >= 0) { 
            System.out.print(arr[k] + " "); 
            k = prev[k]; 
        } 
  
    } 
  
    public static void main(String[] args) { 
  
        int[] x = { 1, 2, 17, 4}; 
  
        // sort the array 
        Arrays.sort(x); 
  
        findLargest(x); 
    } 
} 

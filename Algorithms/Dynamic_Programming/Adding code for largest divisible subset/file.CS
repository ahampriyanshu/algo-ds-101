// C# program to find largest divisible subset in a given array 

using System; 
  
public class DivSubset  
{ 
    public static int[,] dp; 
  
    // Prints largest divisible subset 
    static void findLargest(int[] arr)  
    { 
  
        // array that maintains the maximum index till which the condition is satisfied 
        int []divCount = new int[arr.Length]; 
          
        // we will always have atleast one element divisible by itself 
        for(int i = 0; i < arr.Length; i++) 
            divCount[i] = 1; 
  
        // maintain the index of the last increment 
        int []prev = new int[arr.Length]; 
        for(int i = 0; i < arr.Length; i++) 
            prev[i] = -1; 
  
  
        // index at which last increment happened 
        int max_ind = 0; 
  
        for (int i = 1; i < arr.Length; i++)  
        { 
            for (int j = 0; j < i; j++) 
            { 
  
                // only increment the maximum index if this iteration will increase it 
                if (arr[i] % arr[j] == 0 &&  
                    divCount[i] < divCount[j] + 1)  
                { 
                    prev[i] = j; 
                    divCount[i] = divCount[j] + 1; 
  
                } 
  
            } 
              
        // Update last index of largest subset if size of current subset is more. 
            if (divCount[i] > divCount[max_ind]) 
                max_ind = i; 
        } 
  
        // Print result 
        int k = max_ind; 
        while (k >= 0)  
        { 
            Console.Write(arr[k] + " "); 
            k = prev[k]; 
        } 
    } 
  
    // Driver code 
    public static void Main(String[] args) 
    { 
        int i;
        int[] x = new int[5]; // 5 size array
      
        // Accepting value from user 
        for (i = 0; i < 5; i++)
          {
                Console.Write("\nEnter your "+(i+1)+ " number: ");
                //Storing value in an array
                x[i] = Convert.ToInt32(Console.ReadLine());
          }
        // sort the array 
        Array.Sort(x); 
  
        findLargest(x); 
    } 
} 
  

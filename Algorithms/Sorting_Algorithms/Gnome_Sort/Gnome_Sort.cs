// C# Program to implement Gnome Sort 
using System; 
  
class GFG { 
      
    static void gnomeSort(int[] arr, int n) 
    { 
        int index = 0; 
  
        while (index < n)  
        { 
            if (index == 0) 
                index++; 
            if (arr[index] >= arr[index - 1]) 
                index++; 
            else { 
                int temp = 0; 
                temp = arr[index]; 
                arr[index] = arr[index - 1]; 
                arr[index - 1] = temp; 
                index--; 
            } 
        } 
        return; 
    } 
  
    // Driver program to test above functions. 
    public static void Main() 
    { 
        int[] arr = { 34, 2, 10, -9 }; 
          
        // Function calling 
        gnomeSort(arr, arr.Length); 
  
        Console.Write("Sorted sequence after applying Gnome sort: "); 
  
        for (int i = 0; i < arr.Length; i++) 
            Console.Write(arr[i] + " "); 
    } 
} 
  
// This code is contributed by Sam007 

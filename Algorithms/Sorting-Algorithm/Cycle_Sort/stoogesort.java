import java.io.*; 
  
public class stooge { 
    // Function to implement stooge sort 
    static void stoogesort(int arr[], int l, int h) 
    { 
        if (l >= h) 
            return; 
  
        if (arr[l] > arr[h]) { 
            int t = arr[l]; 
            arr[l] = arr[h]; 
            arr[h] = t; 
        } 
  
        
        if (h - l + 1 > 2) { 
            int t = (h - l + 1) / 3; 
  
           
            stoogesort(arr, l, h - t); 
  
            
            stoogesort(arr, l + t, h); 
            stoogesort(arr, l, h - t); 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        int arr[] = { 2, 4, 5, 3, 1 }; 
        int n = arr.length; 
  
        stoogesort(arr, 0, n - 1); 
  
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " "); 
    } 
} 

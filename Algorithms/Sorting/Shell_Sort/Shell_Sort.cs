class ShellSort 
{ 
    static void printArray(int []arr) 
    { 
        int n = arr.Length; 
        for (int i=0; i<n; ++i) 
        Console.Write(arr[i] + " "); 
        Console.WriteLine(); 
    } 
  
    int sort(int []arr) 
    { 
        int n = arr.Length; 
  
        for (int gap = n/2; gap > 0; gap /= 2) 
        { 
            for (int i = gap; i < n; i += 1) 
            { 
                int temp = arr[i]; 
  

                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                    arr[j] = arr[j - gap]; 
  
                arr[j] = temp; 
            } 
        } 
        return 0; 
    } 

    public static void Main() 
    { 
        int []arr = {12, 34, 54, 2, 3}; 
        Console.Write("Array before sorting :\n"); 
        printArray(arr); 
  
        ShellSort ob = new ShellSort(); 
        ob.sort(arr); 
  
        Console.Write("Array after sorting :\n"); 
        printArray(arr); 
    } 
}  
import java.util.*; 
  
public class DivSubset { 
  
    public static int[][] dp; 
  
    static void findLargest(int[] arr) { 
  
        int divCount[] = new int[arr.length]; 
        Arrays.fill(divCount, 1); 
        
        int prev[] = new int[arr.length]; 
        Arrays.fill(prev, -1); 
        int max_ind = 0; 
  
        for (int i = 1; i < arr.length; i++) { 
            for (int j = 0; j < i; j++) { 

                if (arr[i] % arr[j] == 0 &&  
                    divCount[i] < divCount[j] + 1) { 
                    prev[i] = j; 
                    divCount[i] = divCount[j] + 1; 
                } 
            } 

            if (divCount[i] > divCount[max_ind]) 
                max_ind = i; 
        } 
  
        int k = max_ind; 
        while (k >= 0) { 
            System.out.print(arr[k] + " "); 
            k = prev[k]; 
        } 
    } 
  
    public static void main(String[] args) { 
  
        int[] x = { 1, 2, 17, 4}; 
  
        Scanner s = new Scanner(System.in);

        System.out.println("Enter number of elements");
        int n = s.nextInt();

        int arr[]=new int[n];

        System.out.println("Enter elements");
        for(int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }
        
        Arrays.sort(arr); 
  
        findLargest(arr); 
      
    } 
}

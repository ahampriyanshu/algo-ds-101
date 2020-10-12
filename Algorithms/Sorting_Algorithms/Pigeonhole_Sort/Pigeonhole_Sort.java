import java.lang.*; 
import java.util.*; 
  
public class Pigeonhole_Sort
{ 
    public static void pigeonhole_sort(int arr[], 
                                           int n) 
    { 
        int min = arr[0]; 
        int max = arr[0]; 
        int range, i, j, index;  
  
        for(int a=0; a<n; a++) 
        { 
            if(arr[a] > max) 
                max = arr[a]; 
            if(arr[a] < min) 
                min = arr[a]; 
        } 
  
        range = max - min + 1; 
        int[] phole = new int[range]; 
        Arrays.fill(phole, 0); 
  
        for(i = 0; i<n; i++) 
            phole[arr[i] - min]++; 
  
          
        index = 0; 
  
        for(j = 0; j<range; j++) 
            while(phole[j]-->0) 
                arr[index++]=j+min; 
  
    } 
  
    public static void main(String[] args) 
    { 
        Pigeonhole_Sort sort = new Pigeonhole_Sort(); 
        Scanner obj = new Scanner(System.in);

        int N , i;
        System.out.print("Enter Size of Array :- ");
        N = obj.nextInt();
        int A[] = new int[N];
        System.out.print("Enter Array Elements :- ");
        for(i = 0;i < N;i++)
            A[i] = obj.nextInt();
        System.out.print("Sorted order is : "); 
        sort.pigeonhole_sort(A,A.length); 
          
        for(i=0 ; i<A.length ; i++) 
            System.out.print(A[i] + " "); 
        System.out.println();
    } 
  
} 
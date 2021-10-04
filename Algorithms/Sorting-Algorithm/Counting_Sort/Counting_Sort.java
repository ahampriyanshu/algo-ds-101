package algo_ds_101.Algorithms.Sorting_Algorithms.Counting_Sort;

import java.io.*;
import java.util.*;

class Counting_Sort
{
    public static void main(String[] args) {
        int n, k = 0, i,j;  
        int []A=new int[15];
        int []B=new int[15];
        int []C=new int[100];
        System.out.println("Enter the number of input : ");  
        Scanner sc = new Scanner(System.in);
        n=sc.nextInt();
        System.out.println("\nEnter the elements to be sorted :\n");  
        for (i = 1; i <= n; i++)  
        {  
            A[i]=sc.nextInt();  
            if (A[i] > k) {  
                k = A[i];  
            }  
        }    
        System.out.println("\n");    
  
    for (i = 0; i <= k; i++)  
        C[i] = 0;  
    for (j = 1; j <= n; j++)  
        C[A[j]] = C[A[j]] + 1;  
    for (i = 1; i <= k; i++)  
        C[i] = C[i] + C[i-1];  
    for (j = n; j >= 1; j--)  
    {  
        B[C[A[j]]] = A[j];  
        C[A[j]] = C[A[j]] - 1;  
    }  
    System.out.println("The Sorted array is : ");  
    for (i = 1; i <= n; i++)  
        System.out.println(B[i]);  
  
   
}
}

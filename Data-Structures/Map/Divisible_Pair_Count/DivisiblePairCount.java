import java.io.*;
import java.lang.*;
import java.util.*;
class DivisiblePairCount{ 

public static int countDivisibles(int arr[],int n) 
{ 
    int res = 0; 
    for (int i = 0; i < n; i++)  
    {
	for (int j = i + 1; j < n; j++)  
        {
	    if (arr[i] % arr[j] == 0 ||  arr[j] % arr[i] == 0)  
	    {
	            res++; 
	    }	
  	}
    }
    return res; 
} 
  
public static void main(String[] args) 
{
    Scanner sc  = new Scanner(System.in);
    int num = sc.nextInt();
    int a[] = new int[num];
    for(int i=0;i<num;i++)
    {
	a[i] = sc.nextInt();
    }
    System.out.print(countDivisibles(a, num)); 
} 
} 
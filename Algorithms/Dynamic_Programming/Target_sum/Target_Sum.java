
import java.util.*; 

public class Target_Sum
{ 

static int Sum(int arr[], int n, int i, 
					int sum, int count) 
{ 
	
	if (i == n) 
	{
		if (sum == 0) 
		{ 
			count++; 
		} 
		return count; 
	} 

	count = Sum(arr, n, i + 1, sum - arr[i], count); 
	count = Sum(arr, n, i + 1, sum, count); 
	return count; 
} 
 
public static void main(String[] args) 
{ 
    Scanner sc= new Scanner(System.in);
    int n,sum;
    System.out.println("Enter number of elements in array");
    n = sc.nextInt();
    int [] arr = new int [n];
    System.out.println("Enter array elements");
    for( int i =0 ; i<n ; ++i) arr[i]=sc.nextInt();
    System.out.println("Enter sum");
    sum = sc.nextInt();


	System.out.print(Sum(arr, n, 0, sum, 0)); 
} 
} 


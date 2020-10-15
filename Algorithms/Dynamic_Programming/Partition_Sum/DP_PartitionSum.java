//Code contributed by Aditya Prakash(@PrakashAditya17)
import java.io.*;
import java.util.*;
public class DP_PartitionSum
{
    public static boolean checking(int arr[],int SUM)
    {
        int len=arr.length;
        //arr2[i][j] ->true , when there's subset of arr[0..j-1] having sum=i.
        boolean arr2[][]=new boolean[SUM+1][len+1];
        
        //Here sum->0, then its set true.
        for(int i=0;i<=len;i++)
            arr2[0][i]=true;
        
        //The 0th column is false because sum not equals 0(Except arr[0][0])
        for (int i = 1; i<=SUM;i++) 
            arr2[i][0]=false;
        
        //Rest of the 2d matrix DP is filled up in bottom up manner    
        for (int i=1;i<= SUM;i++) 
        { 
            for (int j=1;j<=len;j++) 
            { 
                arr2[i][j]=arr2[i][j-1]; 
                if (i>=arr[j - 1]) 
                    arr2[i][j]=arr2[i][j] || arr2[i-arr[j-1]][j-1]; 
            } 
        } 
        //The corner most element is where the answer is stored.
        return(arr2[SUM][len]);
        
    }
	public static void main(String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
	    int n;
		System.out.println("Enter array size and the array");
		n=sc.nextInt();
		int sum=0;
	    int a[]=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        a[i]=sc.nextInt();   
	        sum+=a[i];
	    }
	    if(sum%2==1)                   // sum is odd so it can't be divided into 2 subsets.
	        System.out.println("FALSE : NOT POSSIBLE");
	    else   // We check if the even sum can be divided into two subsets or not, using DP                        
	    {
	        System.out.println(checking(a,sum/2));
	    }
	}
}

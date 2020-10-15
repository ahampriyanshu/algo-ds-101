//Code contributed by Aditya Prakash(@PrakashAditya)

import java.io.*;
import java.util.*;
public class KEB
{
        public static boolean check(int p[],int h,int K)    //check if bananas can be eaten in 'h' hrs with speed K
        {
                int t=0;
                for(int i=0;i<p.length;i++)
                {
                        t+=(p[i]-1)/K+1;
                }
                boolean val=t<=h?true:false;
                return val;
        }
        public static void main(String args[])throws IOException
        {
                Scanner sc=new Scanner(System.in);
                System.out.println("Enter the no. of piles of bananas");
                int n=sc.nextInt();
                int a[]=new int[n];
                for(int i=0;i<n;i++)
                        a[i]=sc.nextInt();
                
                System.out.println("Enter H");
                int H=sc.nextInt();
                
                //We use Binary search Technique
                int low=1,high=n;
                while(low<high)
                {
                        int mid=(low+high)/2;
                        if(check(a,H,mid)==false)
                        {
                                low=mid+1;
                        }
                        else
                                high=mid;
                }
                
                System.out.println(low);
         }
}

                

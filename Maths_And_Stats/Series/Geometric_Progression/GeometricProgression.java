import java.lang.*;
public class Main
{
    //Function that prints GP for given value of a, r and n where nth GP=a*r^(n-1)
    static void GP(int a, int r, int n){
        for(int i=0;i<n;i++){
            System.out.print(a*(int)Math.pow(r,i)+ " ");
        }
        System.out.println();
    }
    
    //Function determines if the given array is a GP or no.
    static boolean validGP(int[] ar,int n){
        if(n==1){
            return true;
        }
        int r = ar[1]/ar[0];
        for(int i=1;i<n;i++){
            if(ar[i]/ar[i-1]!=r){
                return false;
            }
        }
        return true;
    }
    
    //Function prints the nth element of GP
    static void nthGP(int a, int r, int n){
        System.out.println(a*(int)Math.pow(r,n-1));
    }
    
    //Funtion for nth partial sum of a geometric sequence
    static void sum(int a, int r, int n){
        int num = a*(1-(int)Math.pow(r,n));
        int deno = 1-r;
        int ans = num/deno;
        System.out.println(n + "th partial sum of a geometric sequence is "+ ans);
    }
  
}
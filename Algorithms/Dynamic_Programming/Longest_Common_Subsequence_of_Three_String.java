import java.io.*;
import java.util.*;
class LCS3Strings { 
    public static int lcsOf3(String X, String Y, String Z, int m,int n, int o) 
    { 
        int[][][] L = new int[m+1][n+1][o+1]; 
  
        for (int i=0; i<=m; i++) 
        { 
            for (int j=0; j<=n; j++) 
            { 
                for (int k=0; k<=o; k++) 
                { 
                    if (i == 0 || j == 0||k==0) 
		    {
                        L[i][j][k] = 0; 
		    }       
                    else if (X.charAt(i - 1) == Y.charAt(j - 1)  && X.charAt(i - 1)==Z.charAt(k - 1)) 
		    {
                        L[i][j][k] = L[i-1][j-1][k-1] + 1; 
		    }       
                    else
		    {
                        L[i][j][k] = Math.max(Math.max(L[i-1][j][k],L[i][j-1][k]), L[i][j][k-1]); 
		    }
                } 
            } 
        } 
      
        return L[m][n][o]; 
    } 
       
    public static void main(String args[]) 
    { 
	Scanner sc = new Scanner(System.in);
        String X = sc.nextLine();
        String Y = sc.nextLine(); 
        String Z = sc.nextLine(); 
       
        int m = X.length(); 
        int n = Y.length(); 
        int o = Z.length(); 
       
        System.out.println("Length of LCS is " + lcsOf3(X, Y,Z, m, n, o)); 
       
    } 
} 
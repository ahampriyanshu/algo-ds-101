 import java.util.*;
 class Tribonacci
 {
	 
        static int tribonacci(int n) {
        int dp[] = {0, 1, 1};
        for (int i = 3; i <= n; ++i)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
    }
	/*Input: n = 4
	  Output: 4
      Reason:
	  T_3 = 0 + 1 + 1 = 2
      T_4 = 1 + 1 + 2 = 4*/
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int size=in.nextInt();  //4
		
		System.out.println(tribonacci(size)); //4
	}
 }
		

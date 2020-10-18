class Solution {
    public static String longestPalindrome(String s) {
        int n=s.length();
        int[][] memory = new int[n][n];
        int maxLen=1;
        int start=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {

                if(i==j)
                {
                    memory[i][j]=1;
                    continue;
                }
                if(j==i+1)
                {
                    memory[i][i+1]=s.charAt(j)==s.charAt(i)?1:0;
                    if (memory[i][i+1]==1 && maxLen<=2)
                    {
                        maxLen=2;
                        start=i;
                    } 
                    continue;
                }   


                if(memory[i+1][j-1]==1 && s.charAt(j)==s.charAt(i))
                {
                    memory[i][j]=1;
                    int len = j-i+1;
                    if(len>=maxLen)
                    {
                        maxLen=len;
                        start=i;
                    }
                }


            }
        }
        return s.substring(start,start+maxLen);
    }
    public static void main(String[] args)
    {
           System.out.println(longestPalindrome("abbaca"));
    }
}
    

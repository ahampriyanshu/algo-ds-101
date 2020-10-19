//using dynamic programming approach to solve

class Solution {
    public static String longestPalindrome(String s) {
        int n=s.length();
        
        //2-d array to store the palindrome status of each substring -> memory[i][j]=1 iff substring s(i,j) is palindrome otheriwise memory[i][j]=0
        int[][] memory = new int[n][n]; 
        int maxLen=1; //maxLen stores current maximum length of palindrome substring
        int start=0; //start stores the start index of the current longest palindrome string

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {

                if(i==j)
                {
                    memory[i][j]=1; //updating memory for substrings of length 1. 
                    continue;
                }
                if(j==i+1)
                {
                    memory[i][i+1]=s.charAt(j)==s.charAt(i)?1:0; //updating memory with substrings of length 2
                    if (memory[i][i+1]==1 && maxLen<=2)
                    {
                        maxLen=2;
                        start=i;
                    } 
                    continue;
                }   

                //for each substring s(i,j) of lenght>2, it is a palindrome if substring s(i+1,j-1) is a palindrome and s(i)==s(j)
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
        return s.substring(start,start+maxLen); //returning longest palindrome substring
    }
    public static void main(String[] args)
    {
           System.out.println(longestPalindrome("abbaca")); //alter statement acc to preferred input
    }
}
    

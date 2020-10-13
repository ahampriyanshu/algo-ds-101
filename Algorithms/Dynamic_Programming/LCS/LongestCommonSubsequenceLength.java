import java.util.Scanner;
class LongestCommonSubsequenceLength{
  public static void main(String[]args){
    //initialize scanner
    Scanner kb=new Scanner(System.in);
    //prompt user for input
    System.out.println("Provide 2 Strings");
    //take in 2 strings
    String s1=kb.nextLine();
    String s2=kb.nextLine();
    //make 2d array for strings (with space for zeroes to pad first row and column)
    int[][]a=new int[s1.length()+1][s2.length()+1];

    //pad firs column with 0s
    for(int i=0; i<=s1.length(); i++)
      a[i][0]=0;
    //pad first column with 0s
    for(int j=0; j<=s2.length(); j++)
      a[0][j]=0;
    /*now loop over the entire 2d matrix and use the following
      recurrence relation: a[i][j]=max(a[i-1][j], a[i][j-1])
      or if the current i,j position has a matching character include a[i-1][j-1] in that calculation.  

      Why does this work?  We take either the longest common subsequence up to character j of string 2 or up to character i of string 1, whichever is better, because each occurrence must be in order, the greater of these two must be best up to index i in string 1 and index j in string 2.  

      However, if the ith character of str1 matches the jth character of str2, then we must consider what happens if the optimal solution through character i-1 and j-1 was the same as i-1 and j or j-1 and i.  Clearly, in either of these cases, by taking the ith character of string 1, which matches the jth character of string 2, we are guaranteed to be better off taking i and j matching character next, because the alternative would be to wait for either i and j+1 or j and i+1 to match, both of which are at least no better than having the same count through i and j.  
    */
    for(int i=0; i<s1.length(); i++)
      for(int j=0; j<s2.length(); j++)
        if(s1.charAt(i)==s2.charAt(j))
          a[i+1][j+1]=Math.max(Math.max(a[i][j]+1, a[i][j+1]),a[i+1][j]);
        else
          a[i+1][j+1]=Math.max(a[i][j+1], a[i+1][j]);

    /*Then we just print out whatever is in the last position in our array since it's the longest common subsequence up through the final characters of each string*/
    System.out.println(a[s1.length()][s2.length()]);
    
  }
}

// Problem - Check if one string is scrambled from another

import java.io.*;
import java.util.*; 

public class Sample
{ 
	static boolean isScramble(String S1, String S2) 
	{ 
		if (S1.length() != S2.length()) 
		{ 
			return false; 
		} 
		int n = S1.length(); 
	
		if (n == 0) 
		{ 
			return true; 
		} 
		
		if (S1.equals(S2)) 
		{ 
			return true; 
		} 
		
		char[] tempArray1 = S1.toCharArray(); 
		char[] tempArray2 = S2.toCharArray(); 
		
		Arrays.sort(tempArray1); 
		Arrays.sort(tempArray2); 
		
		String copy_S1 = new String(tempArray1); 
		String copy_S2 = new String(tempArray2); 
		
		if (!copy_S1.equals(copy_S2)) 
		{ 
			return false; 
		} 
			
		for(int i = 1; i < n; i++) 
		{ 
			if (isScramble(S1.substring(0, i), S2.substring(0, i)) && isScramble(S1.substring(i, n), S2.substring(i, n))) 
			{ 
				return true; 
			} 
	
			if (isScramble(S1.substring(n - i, n), S2.substring(0, i)) && isScramble(S1.substring(0, n - i), S2.substring(i, n))) 
			{ 
				return true; 
			} 
		} 
		return false; 
	} 
	
	public static void main(String[] args) throws IOException
	{ 
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the first string to be checked");
		String str1=br.readLine();
		System.out.println("Enter the second string to be checked");
		String str2=br.readLine();
		
		if (isScramble(str1, str2)) 
		{ 
			System.out.println("Yes"); 
		} 
		else
		{ 
			System.out.println("No"); 
		} 
	} 
} 



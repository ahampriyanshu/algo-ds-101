package com.codenuclear;
 
import java.util.Scanner;
 
public class TowersOfHanoi {
 
	public void solveTowersOfHanoi(int n, String source, String aux, String dest)
	{
		// If only 1 disk, make the move and return.
		if(n==1)
		{
			System.out.println(source+" --> "+dest);
			return;
		}
		
		// Move top n-1 disks from A to B using C as auxiliary.
		solveTowersOfHanoi(n-1, source, dest, aux);
		
		//Move remaining disks from A to C
		System.out.println(source+" --> "+dest);
		
		// Move n-1 disks from B to C using A as auxiliary
		solveTowersOfHanoi(n-1, aux, source, dest);
		
	}
	
	public static void main(String args[])
	{
		TowersOfHanoi obj = new TowersOfHanoi();
		
		System.out.println("Enter number of disks :- ");
	    
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();
		
		System.out.println("Move disks as below illustration.");
		obj.solveTowersOfHanoi(n, "A", "B", "C");
		
	}	
}
 
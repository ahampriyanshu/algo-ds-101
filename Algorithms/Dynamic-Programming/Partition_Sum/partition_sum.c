// A Dynamic Programming based C program to partition problem 
#include <stdio.h> 

// Returns true if arr[] can be partitioned in two subsets of equal sum, otherwise false 
int findPartiion (int arr[], int n) 
{ 
	int sum = 0; 
	int i, j; 
	
	// Calculate sum of all elements 
	for (i = 0; i < n; i++) 
	sum += arr[i]; 
	
	if (sum%2 != 0) 
		return 0; 
	
	int part[sum/2+1][n+1]; 
	
	// initialize top row as true 
	for (i = 0; i <= n; i++) 
		part[0][i] = 1; 
		
	// initialize leftmost column, except part[0][0], as 0 
	for (i = 1; i <= sum/2; i++) 
		part[i][0] = 0;	 
	
	// Fill the partition table in bottom up manner 
	for (i = 1; i <= sum/2; i++) 
	{ 
		for (j = 1; j <= n; j++) 
		{ 
			part[i][j] = part[i][j-1]; 
			if (i >= arr[j-1]) 
				part[i][j] = part[i][j] || part[i - arr[j-1]][j-1]; 
		}		 
	}	 
	
	return part[sum/2][n]; 
}	 

// Driver program to test above function 
int main() 
{ 
	int n,i;
	int arr[10000];
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]); 
	if (findPartiion(arr, n) == 1) 
		printf("Can be divided into two subsets of equal sum"); 
	else
		printf("Can not be divided into two subsets of equal sum"); 
	getchar(); 
	return 0; 
} 

/* Dynamic Programming C implementation of LIS problem */
#include<stdio.h>  
	
/* lis() returns the length of the longest increasing subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[10000]; 
	int i, j;
	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	int mmax=-99999;
	for(i=0;i<n;i++)
	{
		if(mmax<lis[i])
			mmax = lis[i];
	}
	return mmax; 
} 
	
/* Driver program to test above function */
int main() 
{ 
	int n;
	int arr[10000];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("Length of lis is %d\n", lis( arr, n ) ); 

	return 0; 
}

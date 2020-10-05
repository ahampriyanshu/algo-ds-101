#include <stdio.h> 
#include <stdlib.h>

void countSort(int arr[], int len) 
{ 
    int* output = (int*) malloc(len * sizeof(int));
	// Create a count array to store count of inidividul numbers 
	int count[10], i; 

	// Store count of each character 
	for (i = 0; i < len; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] contains cumulative count 
	for (i = 1; i < 10; ++i) 
		count[i] += count[i - 1]; 

	// Build the sorted array 
	for (i = 0; i < len; ++i) 
	{ 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	}
	
	for (i = 0; i < len; i++)
	    arr[i] = output[i];

} 

int main() 
{ 
    //Assumption: Array only contains numbers from 0-9
	int arr[] = {4,3,2,1,4,2,1,5,6,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	countSort(arr, n); 

	printf("Sorted Array:");
	for(int i = 0; i < n; i++)
	{
	    printf("%d ",arr[i]);
	}
	return 0; 
} 

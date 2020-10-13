#include<stdio.h>
#include<stdlib.h>
#define n 4 
void printArray(int arr[], int size) 
{ 
for (int i=0; i < size; i++) 
	printf("%d ",arr[i]); 
} 
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void mergeKArrays(int arr[][n], int a, int output[]) 
{ 
	int c=0; 
	
	for(int i=0; i<a; i++) 
	{ 
		for(int j=0; j<n ;j++) 
			output[c++]=arr[i][j]; 
	} 
	
	qsort(output,n*a,sizeof(int),cmpfunc); 
	
} 


int main() 
{
	int arr[][n] = {{2, 6, 12, 34}, 
					{1, 9, 20, 1000}, 
					{23, 34, 90, 2000}}; 
	int k = sizeof(arr)/sizeof(arr[0]); 
	
	int output[n*k]; 
	
	mergeKArrays(arr, 3, output); 

	printf("merged array is \n"); 
	printArray(output, n*k); 

	return 0; 
} 

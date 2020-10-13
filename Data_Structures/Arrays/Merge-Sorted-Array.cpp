#include<bits/stdc++.h> 
using namespace std; 
#define n 4 


void printArray(int arr[], int size) 
{ 
for (int i=0; i < size; i++) 
	cout << arr[i] << " "; 
} 

void mergeKArrays(int arr[][n], int a, int output[]) 
{ 
	int c=0; 
	
	for(int i=0; i<a; i++) 
	{ 
		for(int j=0; j<n ;j++) 
			output[c++]=arr[i][j]; 
	} 
	
	sort(output,output + n*a); 
	
} 


int main() 
{
	int arr[][n] = {{2, 6, 12, 34}, 
					{1, 9, 20, 1000}, 
					{23, 34, 90, 2000}}; 
	int k = sizeof(arr)/sizeof(arr[0]); 
	
	int output[n*k]; 
	
	mergeKArrays(arr, 3, output); 

	cout << "Merged array is " << endl; 
	printArray(output, n*k); 

	return 0; 
} 

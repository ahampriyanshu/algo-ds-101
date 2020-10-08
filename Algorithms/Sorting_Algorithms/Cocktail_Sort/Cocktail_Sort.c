// C implementation of Cocktail Sort 
#include <stdio.h> 

//Swap Utility Func
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Sorts arrar a[0..n-1] using Cocktail sort 
void CocktailSort(int a[], int n) 
{ 
	int swapped = 1; 
	int start = 0; 
	int end = n - 1; 
	int i;

	while (swapped) { 
		swapped = 0; 

		for (i = start; i < end; ++i) { 
			if (a[i] > a[i + 1]) { 
				swap(&a[i], &a[i + 1]); 
				swapped = 1; 
			} 
		} 

		if (!swapped) 
			break; 

		swapped = 0; 
		--end; 

		for (i = end - 1; i >= start; --i) { 
			if (a[i] > a[i + 1]) { 
				swap(&a[i], &a[i + 1]); 
				swapped = 1; 
			} 
		} 
		++start; 
	} 
} 

/* Prints the array */
void printArray(int a[], int n) 
{ 
	int i;
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n"); 
} 

// Driver code 
int main() 
{ 
	int n,i;
	int arr[10000];
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	CocktailSort(arr, n); 
	printf("Sorted array :\n"); 
	printArray(arr, n); 
	return 0; 
} 

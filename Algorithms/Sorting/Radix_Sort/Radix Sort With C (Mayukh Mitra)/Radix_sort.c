#include <stdio.h>

//Function to get maximum value in the array... 
int max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//Counting Sort...
void counting_sort(int arr[], int n, int j)
{
	int output[n]; 
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / j) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / j) % 10] - 1] = arr[i];
		count[(arr[i] /j) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// Radix Sort...
void radix_sort(int arr[], int n)
{
	// Finding the number of digits...
	int m = max(arr, n);

	// Performing counting sort for every digit...
	for (int j = 1; m / j > 0; j *= 10)
		counting_sort(arr, n, j);
}

int main()
{
    int n = 10; // Size of the array...

    // The elements of the array...
	int arr[] = { 12, 89, 45, 4, 11, 67, 32, 100, 3, 33 };
	
	radix_sort(arr, n);

    // Printing the array after performing radix sort on it...
	for (int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	return 0;
}

/* This code is contributed by Mayukh Mitra */

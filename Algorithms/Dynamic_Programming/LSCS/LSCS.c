#include <stdio.h>
#include <limits.h>

int largest_subarray_sum(int *arr, int size)
{
	if (size <= 0) {
		printf("Size must be a positive integer\n");
		return 1;
	}

	int start = 0, best_start = 0, best_end = 0;
	int sum = 0, best_sum = INT_MIN;

	for (int end = 0; end < size; ++end) {
		if (sum <= 0) {
			start = end;
			sum = arr[end];
		} else {
			sum += arr[end];
		}

		if (sum > best_sum) {
			best_sum = sum;
			best_start = start;
			best_end = end;
		}
	}
	printf("Best sum is %d\nFirst index: %d\nLast index: %d\n",
			best_sum, best_start, best_end);
	
	return 0;
}

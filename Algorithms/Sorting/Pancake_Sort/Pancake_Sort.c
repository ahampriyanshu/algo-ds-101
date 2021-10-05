#include <stdlib.h>
#include <stdio.h>

//functio to reverse the array.
void flip(int arr[], int i)
{
	int temp, start = 0;
	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

//function to find maximum in the array
int findMax(int arr[], int n)
{
	int mi, i;
	for (mi = 0, i = 0; i < n; ++i)
		if (arr[i] > arr[mi])
			mi = i;
	return mi;
}

//function to perform PancakeSort
int pancakeSort(int *ar, int n)
{
	//the main idea behind the algo is
	//take the greatest element to the first position
	//then flip the aray from the end
	//so that greatest element becomes last element
	//and then reduce the curr_size
	//perfrom these operations till the array get sorted.

	for (int curr_size = n; curr_size > 1; curr_size--)
	{
		int mi = findMax(ar, curr_size);
		if (mi != curr_size - 1)
		{
			//this calls for flipping the array elements.
			flip(ar, mi);
			flip(ar, curr_size - 1);
		}
	}
	return 0;
}

int main()
{
	//input no. of elements required in array ar
	int n;
	scanf("%d", &n);

	int ar[n];

	//input elements in the array
	for (int i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	//Pancake Sort Algorithm
	//The idea behind this algorithm is similar to that of selection sort.

	//the only thing we must perform is flipping the array elements from (0,i)
	//our aim is to sort the array and not focus on time complexity
	//thus total time complexity of this code : O(n^2);
	//total O(n) flips will be performed.

	pancakeSort(ar, n);

	for (int i = 0; i < n; i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
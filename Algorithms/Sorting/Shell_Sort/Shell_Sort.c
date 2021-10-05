#include <stdio.h>
#include <stdlib.h>

int main()
{
	//input size of the array ar
	int n;
	scanf("%d", &n);
	int ar[n];

	//input elements in ar[n]
	for (int i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	//shell sort algorithm
	//shell sort is a variation of insertion sort.

	//gap = [n/2], floor value.
	//we try to sort elements with this gap
	//we continue reducing the gap until it reaches 1.

	//complexity becomes O(n*logn)

	int gap, i, j, temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = ar[i];
			j = i - gap;
			while (j >= 0 && ar[j] > temp)
			{
				ar[j + gap] = ar[j];
				j = j - gap;
			}
			ar[j + gap] = temp;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}

#include <stdio.h>
#include<stdlib.h>

void TOH(int n, char A, char B, char C)
{
	if (n > 0)
	{
		TOH(n - 1, A, C, B);
		printf("Move disk %d from %c to %c", n, A, C);
		printf("\n");
		TOH(n - 1, B, A, C);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	//How the TOH works
	//We basically create a recurrence relation
	//by observing the patterns for n = 1, and n = 2, and n = 3

	//The total recursive approach gives a large time comlexity
	//thus this algo works for lower contraints on "n"

	//Total time complexity : O(2^n)

	TOH(n, 'A', 'B', 'C'); // A, B and C are names of the disks

	return 0;
}

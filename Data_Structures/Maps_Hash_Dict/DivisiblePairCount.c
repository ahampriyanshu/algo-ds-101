#include "stdio.h"
#include <stdlib.h>

int DivisiblePairsCount(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i) {                             // Iterating through each pair.
       for (int j = i+1; j < n; ++j) {
            if (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0)              // Checking for problem condition.
              res++;
       }
    }
    return res;
}

int main()
{
    int n;
    int *arr;
    printf("Enter Size of the Array:  ");
    scanf("%d", &n);

    arr = malloc(sizeof(int) * n);

    printf("Enter the Array Elements:  ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Number of Divisible Pairs: %d \n", DivisiblePairsCount(arr, n));

    return 0;
}

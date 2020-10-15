// Selection sort with Execution Time in C

#include <stdio.h>
#include<time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int step,i;
void selectionSort(int arr[], int size)
{
    for (step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (i = step + 1; i < size; i++)
        {
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
        swap(&arr[min_idx], &arr[step]);
    }
}
void printArray(int arr[], int size)
{
    for (i = 0; i < size; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main()
{
    clock_t start,end;
    double cpu_time_used;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Old Array:- 64 34 25 12 22 11 90\n");
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("Sorted array:-");
    printArray(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Execution Time:- %lf",cpu_time_used);
}

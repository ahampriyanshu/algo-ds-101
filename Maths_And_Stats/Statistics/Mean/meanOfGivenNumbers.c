#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 23, 423, 45, 34, 2, 36, 256, 2, 143};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float mean;
    for (int i = 0; i < size; i++)
        sum = sum + arr[i];
    mean = (float)sum / size;
    printf("\nThe mean of %d numbers is %f\n", size, mean);
    return 0;
}
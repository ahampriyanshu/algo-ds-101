#include <stdio.h>
 
// Two pointer technique based solution to find
int isPairSum(int A[], int N, int X)
{
    // Represents first pointer
    int i = 0;
 
    // Represents second pointer
    int j = N - 1;
 
    while (i < j)
    {
        // If we find a pair
        if (A[i] + A[j] == X)
            return 1;
 
        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;
 
        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return 0;
}
 
// Main method
int main()
{
    // Array declaration
    int arr[] = { 3, 5, 9, 2, 8, 10, 11 };
     
    // Custom value to be searched
    int val = 17;
     
    // size of the array
    int arrSize = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    printf("%d", isPairSum(arr, arrSize, val));
 
    return 0;
}

#include <stdio.h>
//swap of elements
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
//arrange the array in high low order
void rearrange(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i - 1] > arr[i]) {
            swap(arr, i - 1, i);
        }
        if (i + 1 < n && arr[i + 1] > arr[i]) {
            swap(arr, i + 1, i);
        }
    }
}
 
int main(void)
{
    //take input from user
    int n;
    printf("Enter array length : \n");
    scanf("%d",&n);
    
    int arr[n];
    
     printf("Enter array elements:\n");
     for(int i = 0; i < n;  i++){
        scanf("%d", &arr[i]);
     }
 
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}

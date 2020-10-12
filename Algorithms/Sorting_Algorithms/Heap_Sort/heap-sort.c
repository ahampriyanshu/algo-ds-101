#include <stdio.h>

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

// heapify
void heapify(int arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2;  
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
// heap sort 
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
 
    for (int i=n-1; i>0; i--) 
    { 
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Main Function 
int main() 
{
    int n;
    int arr[100];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
  
    heapSort(arr, n); 
  
    printf("Sorted array is \n"); 
    printArray(arr, n); 
} 

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    int* ptr;
    int n;
 
    printf("Enter number of elements:\n");
    scanf("%d",&n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
  
 
    // Get the elements of the array
    printf("Input the elements of the array\n");
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d",&ptr[i]);
    }
 
    printf("The elements of the array are:\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%d ", ptr[i]);
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // number of elements in array
    int i; 
    int *ptr;  //dynamic allocation of array
    int element;  // number to find

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter the number to find: ");
    scanf("%d", &element);

    ptr = (int*) malloc(n * sizeof(int));
 
    // if memory cannot be allocated
    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }

    for(i=0;i<n;i++){
		if(ptr[i]==element){
			printf("Yes \n");
			return 0;
		}
	}
	printf("NO \n");

    free(ptr);

    return 0;
}
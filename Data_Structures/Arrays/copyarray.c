#include<stdio.h>
int main()
{
    int arr1[40],n,i,arr2[40];

    printf("How many number :");
    scanf("%d",&n);

    // scan  array_1 Elements;
    for (i=0;i<n;i++)
        {
            scanf("%d",&arr1[i]);
        }

    // Print Array_1
    printf("Array_1 : ");
    for(i=0;i<n;i++)

    {
        printf("%d ",arr1[i]);
    }
    printf("\n");

// copy all Elements
    for (i=0;i<n;i++)
    {
        arr2[i]=arr1[i];
    }


    // Print Array_2
    printf("Array_2 : ");
    for (i=0;i<n;i++)
    {
     printf("%d ",arr2[i]);
    }


 getchar();
}

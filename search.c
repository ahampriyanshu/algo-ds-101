#include<stdio.h>
#include<conio.h>  
int main()
{
    int ,i,x,n,a[10];
    printf("enter the number of elements");
    scanf("%d",&n);
     
    printf("Enter the elements:n");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
     
    printf("Enter element to be searched:");
    scanf("%d",&x);
     
    for(i=0;i<n;++i)
        if(a[i]==x)
            break;
     
    if(i<n)
        printf("Element found at index %d",i);
    else
        printf("Element not found");
  
    return 0;
}

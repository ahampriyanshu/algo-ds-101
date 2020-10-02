#include<stdio.h>
#define max 50
int mode(int b[],int n)
{
    int maxcount=0;   
    int mode=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(b[j]==b[i])
                c++;
        }
        if(c>maxcount)
        {
            maxcount=c;
            mode=b[i];
        }
    }
    return mode;
}
int main()
{
    int n;
    printf("Enter total number of elements\n");
    scanf("%d",&n);
    int a[max];
    printf("Enter the elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Mode= %d",mode(a,n));
}

#include<stdio.h>
#define MAX 100
int main()
{
    int arow,acolumn,brow,bcolumn,i,j,k;
    int a[MAX][MAX],b[MAX][MAX],product[MAX][MAX];
    int sum=0;

    printf("Enter the number of row and column of matrix A:");
    scanf("%d%d",&arow,&acolumn);
    printf("Enter the elements of matric A:");
    for(i=0;i<arow;i++);
    {
        for(j=0;j<acolumn;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and column of amtrix B:");
    scanf("%d%d",&brow,&bcolumn);
    if(brow!=acolumn)
        printf("Invalid input of matric B");
    else
    {
        printf("Ente the elements of matric B");
        for(i=0;i<brow;i++);
        {
            for(j=0;j<bcolumn;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
    }
    for(i=0;i<arow;i++)
    {
        for(j=0;j<bcolumn;j++)
        {
            for(k=0;k<brow;k++)
            {
                sum+=a[i][k]*b[j][k];
            }
        product[i][j]=sum;
        sum=0;
        }
    }
    printf("The Resultant matric:\n");
    for(i=0;i<arow;i++)
    {
        for(j=0;j<bcolumn;j++)
        {
            printf("%d",product[i][j]);
        }
        printf("\n");
    }
    return 0;
}
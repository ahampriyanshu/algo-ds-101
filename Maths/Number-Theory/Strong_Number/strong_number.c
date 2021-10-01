#include <stdio.h>  
int main()  
{  
    int n;  
    int sum=0;  
    printf("Enter a number");  
    scanf("%d",&n);  
    int k=n;  
    int r;  
    while(k!=0)  
    {  
        r=k%10;  
        int f=fact(r);  
        k=k/10;  
        sum=sum+f;  
    }  
    if(sum==n)  
    {  
        printf("\nNumber is a strong");  
    }  
    else  
    {  
        printf("\nNumber is not a strong");  
    }  
    return 0;  
}  
int fact(int r)  
{  
    int mul=1;  
    for(int i=1;i<=r;i++)  
    {  
        mul=mul*i;  
    }  
    return mul;  
      
}  
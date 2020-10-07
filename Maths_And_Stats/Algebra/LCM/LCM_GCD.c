#include<stdio.h>
int main()
{
    int x,y,gcd,lcm;
    printf("Enter any two number to find LCM AND GCD:");
    scanf("%d%d",&x,&y);
    if(x>y)
        z=x;
    else
    {
        z=y;
    }
    for(gcd=z;gcd>=1;gcd--)
    {
        if(x%gcd==0 && y%gcd==0)
        break;
    }
    printf("The Gcd of %d,%d = %d",x,y,gcd);
    lcm=(x*y)/gcd;
    printf("The Lcm of %d, %d = %d",x,y,lcm);
    return 0;
}
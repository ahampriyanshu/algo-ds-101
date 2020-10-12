#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    int fact = 1, i;
    for (i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    int num;
    printf("Enter a non-negative number: ");
    scanf("%d",&num);
    if(num<0){
        printf("Factorial of a negative integer cannot be found");
    }
    else{
    printf("Factorial of %d is %d", num , factorial(num));
    }
    return 0;
}
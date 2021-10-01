#include<stdio.h>
#include<math.h>

int main(){
    int b, e, m;
    printf("Enter the base value: ");
    scanf("%d", &b);
    printf("Enter the exponent value: ");
    scanf("%d", &e);
    printf("Enter the modulus value: ");
    scanf("%d", &m);
    int power, res;
    power = pow(b,e);
    res = power%m;
    printf("The modular exponentiation of the given set of values is: %d",res);

    return 0;
}
/*C Program to find the Sum of Arithmetic Progression Series */
#include<stdio.h>

float AP( float a, float d, int n){
 return ( ( n / 2)*( ( 2 * a ) + ( ( n - 1 )* d ) ) );
}

int main(){
 float d = 0, a = 0, result = 0;
 int n = 0;
 printf("Enter the First Term [a], Common Difference[d], Number of Terms[n] of an Arithmetic Series :");
 scanf("%f%f%d", &a, &d, &n );

 result =  AP( a, d, n);
 printf("The sum of the Series : %0.2f\n", result);

 return 0;
}

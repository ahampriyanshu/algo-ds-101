/*
Babylonian is used to find the square root of a number.
It is a very old method.
*/

#include<stdio.h>
/*
  squareRoot function
  @param:num the number whose square root is to find.
  return square root of the number in float.
*/
float squareRoot( int num ){
 float x = num, y = 1.0, diff = 0.000001;

 while( x - y > diff  ){
  x = ( x + y ) / 2 ;
  y = num / x ;
 }
 return x;
}

//main function
int main(){
 int num = 0;
 float result = 0.0;
 printf( "Enter a number to find Square Root :" );
 scanf( "%d", &num );
 result = squareRoot( num );

 if( num < 0 ){
    printf( "Square Root is not real for negative numbers. \n");
    return 0;
 }

 printf( "The Square Root of %d : %f\n", num, result );
 return 0;
}

// Contributed by Vishwaroop Shah

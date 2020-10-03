// Nothing Special

#include <stdio.h> 
#include <math.h> 

// Function for conversion 
double Convert(double degree) {
    double pi = 3.14159265359;
    return (degree * (pi / 180)); 
} 

// Driver code 
int main() { 
    double degree;
    printf("Enter a value:\n");
    scanf("%lf" , &degree);
    double radian = Convert(degree);
    printf("%lf\n" , radian);
    return 0; 
} 

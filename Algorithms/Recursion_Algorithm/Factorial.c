/**
 * Factorial
 * 
 * @author Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"

int run(int value){
    if(value <= 1) return 1;
    return value * run(value - 1);
}

int main(int argc, char const *argv[]){

    int number = 6;
    printf("Factorial of %d: %d\n", number, run(number));
    
    return 0;
}

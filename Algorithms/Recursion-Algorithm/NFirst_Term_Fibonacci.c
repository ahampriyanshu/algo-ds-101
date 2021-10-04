/**
 * First N terms of the Fibonacci sequence
 * 
 * @author Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"

void fib(int actual, int last, int end){
    if(end == 0) return;
    
    printf("%d ", actual);
    fib(actual + last, actual, end - 1);
}

int main(int argc, char const *argv[]){

    int n_firsts_el = 15;

    printf("----- N(%d) First Terms of the sequence of Fibonacci-----\n", n_firsts_el);
    fib(0, 1, n_firsts_el);
    printf("\n");
    return 0;
}

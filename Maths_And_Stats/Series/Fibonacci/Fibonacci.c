// Nothing Special

#include <stdio.h>
#include <inttypes.h>

int main() {
    int32_t t1 = 0 , t2 = 1 , next_term;
    
    int32_t n;  scanf("%" PRId32 , &n);

    puts("Fibonacci Series ...");

    for (int32_t i = 0; i <= n; i++) {
        printf("%" PRId32 "\t" , t1);
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
    printf("\n");
    return 0;
}

// Nothing Special

#include <stdio.h>

int main() {
    int a1,b1,c1,a2,b2,c2;

    printf("Enter the 1st Vector\n\n");
    printf("A1 = ");    scanf("%d" , &a1);
    printf("B1 = ");    scanf("%d" , &b1);
    printf("C1 = ");    scanf("%d" , &c1);

    printf("Enter the 2nd Vector\n\n");
    printf("A2 = ");    scanf("%d" , &a2);
    printf("B2 = ");    scanf("%d" , &b2);
    printf("C2 = ");    scanf("%d" , &c2);

    puts("");

    printf("Vector Product of both vectors is %d %d %d\n" , (b1 * c2) - (b2 * c1) , (a1 * c2) - (a2 * c1) , (a1 * b2) - (a2 * b1));
    return 0;
}

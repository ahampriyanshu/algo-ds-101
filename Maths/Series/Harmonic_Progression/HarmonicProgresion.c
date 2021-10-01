#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int terms, i, first, denominator, diff;
    float sum = 0.0;
    printf("Enter the number of terms in HP series\n");
    scanf("%d", &terms);
 
    printf("Enter denominator of first term and common difference of HP series\n");
    scanf("%d %d", &first, &diff);
 
    denominator = first;
    printf("HP SERIES\n");
    for(i = 0; i < terms; i++) {
        printf("1/%d ", denominator);
        sum += 1/(float)denominator;
        denominator += diff;
    }
 
    printf("\nSum of the HP series till %d terms is %f\n", terms, sum);
 
    getch();
 return 0;
}

/*Enter the number of terms in HP series
5
Enter denominator of first term and common difference of HP series
2 4
HP SERIES
1/2 1/6 1/10 1/14 1/18
Sum of the HP series till 5 terms is 0.893651*/

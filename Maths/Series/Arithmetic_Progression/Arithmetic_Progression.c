#include <stdio.h>

void main(){
    int a, n, d, i;

    printf("Enter the first term: ");
    scanf("%d", &a);
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the difference between the terms: ");
    scanf("%d", &d);

	printf("AP: ");
    for (i = 0; i < n; i++)
        printf("%d ", a + (i * d));
}

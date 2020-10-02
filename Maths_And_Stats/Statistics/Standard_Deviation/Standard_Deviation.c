#include <math.h>
#include <stdio.h>

//function to calculate standard deviation
float calculateSD(float data[],int n);
int main() {
    int i,n;
    printf("Enter total No. of  elements: ");
    scanf("%d", &n);
    float data[n];
    printf("Enter %d elements: ",n);
    for (i = 0; i < n; ++i)
        scanf("%f", &data[i]);
    printf("\nStandard Deviation = %.6f", calculateSD(data,n));
    return 0;
}

float calculateSD(float data[],int n) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        sum += data[i];
    }
    mean = sum / n;
    for (i = 0; i < n; ++i)
        SD += pow(data[i] - mean, 2);
    return sqrt(SD / n);
}

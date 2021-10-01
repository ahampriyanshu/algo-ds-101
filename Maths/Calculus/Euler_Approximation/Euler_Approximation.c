#include<stdio.h>
#include<stdlib.h>

float fun(float x, float y)
{
    float f;
    f = x + y;
    return f;
}

int main()
{
    //input x0, y0, h, t
    //basic formula implementation is required.
    float a, b, x, y, h, t, k;

    printf("\nEnter x0, y0, h, xn: ");
    scanf("%f%f%f%f", &a, &b, &h, &t);
    printf("\n");

    x = a;
    y = b;
    printf("\nX and Y respectively are: \n");

    //basic formula implementation
    while (x <= t)
    {
        k = h * fun(x, y);
        y = y + k;
        x = x + h;
        printf("%0.3f, %0.3f\n", x, y);
    }
}
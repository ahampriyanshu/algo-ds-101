#include <stdio.h>
#define max 10

int main()
{
    int array[max], pos, i, n, value;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    if (n <= max)
    {
        printf("Enter %d elements:\n", n);

        for (i = 0; i < n; i++)
        {
            scanf("%d\n", &array[i]);
        }
        printf("Enter the location where you want to insert an element: ");
        scanf("%d", &pos);

        printf("Enter the value to insert: ");
        scanf("%d", &value);

        for (i = n - 1; i >= pos - 1; i--)
            array[i + 1] = array[i];

        array[pos - 1] = value;

        printf("Resultant array:\n");

        for (i = 0; i <= n; i++)
            printf("%d\n", array[i]);
    }
    else
    {
        printf("Array out of bound.");
    }

    return 0;
}

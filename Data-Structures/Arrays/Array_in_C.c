# Tried an array of Characters in a string example with my name.

#include <stdio.h>
int main()
{
    char str[100]="Shyamashrita";
    int i = 0;
        
    printf("\nThe String: %s\n\n",str);
        
    while (str[i] != '\0')
    {
        printf("The Character at %d Index Position = %c \n", i+1, str[i]);
        i++;
    }
    return 0;
}
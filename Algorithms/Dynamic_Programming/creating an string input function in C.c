#include <stdio.h>

int input(char str[],int n)
{
    int ch;
    int i=0;
    while((ch=getchar())!='\n')
    {
        if(i<n)
        str[i++]=ch;
    }
    str[i]='\0';
    return i;
}

int main()
{
   char str[100];
   printf("Enter your line \n");
   int n = input(str,20);
   printf("%d %s",n,str);
}

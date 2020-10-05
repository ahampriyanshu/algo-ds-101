#include<stdio.h>
#include<stdlib.h>
int main()
{
      int first_term, second_term, third_term;
      int limit, count;
      printf("Enter the Limit :-\n");
      scanf("%d", &limit);
      first_term = 2;
      second_term = 1;
      printf("Series :-\n");
      for(count = 0; count < limit; count++)
      {
            printf("%d ", first_term);
            third_term = first_term + second_term;
            first_term = second_term;
            second_term = third_term;
      }
      printf("\n");
      return 0;
}
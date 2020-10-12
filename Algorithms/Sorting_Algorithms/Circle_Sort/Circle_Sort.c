#include <stdio.h>
#include <stdlib.h>

int circle_sort_inner(int *start, int *end)
{
  int *p, *q, t, swapped;
 
  if (start == end) return 0;
  for (swapped = 0, p = start, q = end; p<q || (p==q && ++q); p++, q--)
    if (*p > *q)
      t = *p, *p = *q, *q = t, swapped = 1;
 
  return swapped | circle_sort_inner(start, q) | circle_sort_inner(p, end);
}

void circle_sort(int a[], int n) 
{ 
    while (circle_sort_inner(a, a + (n - 1))) 
    { 
       ; 
    } 
} 
 
int main(void)
{
  int N , i ,j;
  printf("Enter Size of Array :- \n");
  scanf("%d",&N);
  int A[N];
  for(i = 0 ; i < N;i++)
    scanf("%d",&A[i]);

  circle_sort(A, N);
  printf("Sorted Array :- \n");
  for(i = 0 ; i < N;i++)
    printf("%d ",A[i]);
  printf("\n");

  return 0;
}
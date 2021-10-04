#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int newGap(int gap) {
  gap = (gap * 10) / 13;
  if (gap == 9 || gap == 10)
    gap = 11;
  if (gap < 1)
    gap = 1;
  return gap;
}
void combsort(int a[], int aSize) {
  int gap = aSize;
  for (;;) {
    gap = newGap(gap);
    bool swapped = false;
    for (int i = 0; i < aSize - gap; i++) {
      int j = i + gap;
      if (a[i] > a[j]) {
        int temp=a[i];
           a[i]=a[i + gap];
           a[i + gap]=temp;
        swapped = true;
      }
    }
    if (gap == 1 && !swapped)
      break;
  }
}
int main()
{
    int i , N;
    printf("Enter Size of Array :-\n");
    scanf("%d",&N);
    int A[N];
    printf("Enter Array Elements :-\n");
    for(i = 0 ;i < N;i++)
        scanf("%d",&A[i]);
    combsort(A , N);
    printf("Sorted Array :-\n");
    for(i = 0 ;i < N;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

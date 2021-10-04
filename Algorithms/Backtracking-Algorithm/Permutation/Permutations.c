#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void swap(int *ar, int i, int j)
{
  int temp = ar[i];
  ar[i] = ar[j];
  ar[j] = temp;
}

void printar(int *ar, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", ar[i]);

  printf("\n");
}

void permute(int *ar, int i, int n)
{
  if (n == i) {

    printar(ar, n);
    return;
  }

  int j = i;
  for (j = i; j < n; j++)
  {
    swap(ar, i, j);
    permute(ar , i + 1, n);
    swap(ar, i, j);
  }

  return;
}

int main()
{
  int n;
  scanf("%d", &n);

  int ar[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &ar[i]);

  permute(ar, 0, n);

}
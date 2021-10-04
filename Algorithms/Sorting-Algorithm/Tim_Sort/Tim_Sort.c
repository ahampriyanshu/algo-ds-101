//C Program for Tim Sort
#include<stdio.h>

const int run = 32;
//Function to find minimum of two numbers
int min (int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}
//function implementing insertion sort 
void insertionSort (int a[], int low, int high)
{
  int i, j, temp;
  for (i = low + 1; i <= high; i++)
    {
      temp = a[i];
      j = i - 1;
      while (a[j] > temp && j >= low)
        a[j + 1] = a[j--];
      a[j + 1] = temp;
    }
}
//function implementing merge sort
void merge (int a[], int left, int mid, int right)
{
  int len1 = mid - left + 1;
  int len2 = right - mid;
  int low[len1], high[len2];
  int i, j, k;
  for (i = 0; i < len1; i++)
    low[i] = a[left + i];
  for (i = 0; i < len2; i++)
    high[i] = a[mid + 1 + i];

  i = 0; j = 0;
  k = left;

  while (i < len1 && j < len2)
    {
      if (low[i] <= high[j])
	   a[k] = low[i++];
      else
	   a[k] = high[j++];
      k++;
    }
    while (i < len1)
      a[k++] = low[i++];

    while (j < len2)
      a[k++] = high[j++];
}

void timSort (int a[], int n)
{
  int i, size, low, mid, high;
  for (i = 0; i < n; i += run)
    insertionSort (a, i, min ((i + 31), (n - 1)));
  for (size = run; size < n; size = 2 * size)
  {
    for (low = 0; low < n; low += 2 * size)
	{
	  mid = low + size - 1;
	  high = min ((low + 2 * size - 1), (n - 1));
      merge (a, low, mid, high);
	}
  }
}

void main ()
{
  int a[50] , n, i;
  //Get number of elements from user
  printf("Enter number of elements to be sorted:");
  scanf("%d",&n);
  //Get elements from user into array
  printf("Enter the elements:");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  //Apply timsort to the array
  timSort (a, n);
  //Print the sorted array
  printf ("Printing sorted array elements \n");
  for (i = 0; i < n; i++)
    printf ("%d  ", a[i]);
  printf ("\n");
}

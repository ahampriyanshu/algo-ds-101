#include<stdio.h>

#include<stdlib.h>

void pigeonhole_sort(int arr[], int num, int min, int max)
{
  int size,i,j,k,count;
  size = max - min + 1;
  int holes[size];
  for(i=0;i<size;i++)
    holes[i]=0;
  for (j=0; j < num ;j++)
    holes[arr[j] - min]++;
  k=0;
  for (count = 0; count < size; count++)

  while (holes[count]-- > 0)
  {
    arr[k] = count + min;
    k=k+1;
  }
}
int main()
{
    int i,n, c, d, t;
    printf("Enter the number of Elements : ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements to be sorted :\n");
    
    for (i = 0; i < n; i++)
        scanf("%d",&array[i]);
        
    int min = array[0] , max = array[0];

    for (i = 1; i < n; i++)
    {
        if(min > array[i])
          min = array[i];
        if(max < array[i])
          max = array[i];
    }
    pigeonhole_sort(array, n,min,max);
    printf("Sorted Array :\n");
    for(i = 0; i < n; i++)
      printf("%d ",array[i]);
    printf("\n");

return 0;

}
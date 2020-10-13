#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
 	int aSize, bSize, cSize, mSize, i, j;
	int a[10], b[10], c[10], Merged[20];
  
 	printf("\n Please Enter the First Array Size  :  ");
 	scanf("%d", &aSize);
 
 	printf("\nPlease Enter the First Array Elements :  ");
 	for(i = 0; i < aSize; i++)
  	{
      	scanf("%d", &a[i]);
  	}
  	printf("\n Please Enter the Second Array Size  :  ");
 	scanf("%d", &bSize);
   
 	printf("\nPlease Enter the Second Array Elements  :  ");
 	for(i = 0; i < bSize; i++)
  	{
      	scanf("%d", &b[i]);
  	}
  	printf("\n Please Enter the Third Array Size  :  ");
 	scanf("%d", &cSize);
 	printf("\nPlease Enter the Third Array Elements  :  ");
    for(i = 0; i < cSize; i++)
  	{
      	scanf("%d", &c[i]);
  	}
  	for(i = 0; i < aSize; i++)
  	{
      	Merged[i] = a[i];
  	}
	mSize = aSize + bSize;
 
 	for(i = 0, j = aSize; j < mSize && i < bSize; i++, j++)
  	{
  		Merged[j] = b[i];
  	}
  	mSize = aSize + bSize + cSize;
  	for(i = 0, j = aSize + bSize; j < mSize && i < cSize; i++, j++)
  	{
  		Merged[j] = c[i];
  	}
    qsort(Merged,mSize,sizeof(int),cmpfunc);
 	printf("\n a[%d] Array Elements After Merging \n", mSize); 
 	for(i = 0; i < mSize; i++)
  	{
    	printf(" %d \t ",Merged[i]);
  	}
 
  	return 0;
}
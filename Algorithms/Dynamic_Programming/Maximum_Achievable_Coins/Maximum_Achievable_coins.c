#include <stdio.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}

int main(void) {
	int numb;
	//I am assuming even input for numb 
	scanf("%d",&numb);
	int coins[numb];
	for(int i=0;i<numb;i++)
	    scanf("%d",&coins[i]);
	bubbleSort(coins,numb);//function call above lol
	int sum=0;
	for(int i=numb-1;i>(numb/2)-1;i--)//looks complicated but i dont wanna use many variable to depict all the calculation
	    sum += coins[i];
	
	printf("%d",sum);
	return 0;
}


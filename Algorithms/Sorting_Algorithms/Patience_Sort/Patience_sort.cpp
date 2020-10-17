//The code is in C
#include<stdlib.h>
#include<stdio.h>

//sorting function
int* patienceSort(int* arr, int size)
{
    //variables and array declaration
	int decks[size][size], min, pickedRow;

    //Dynamic memory allocation
	int *count = (int*)calloc(sizeof(int),size);
    int *sortedArr = (int*)malloc(size*sizeof(int));
    //creating a pile just like in the game of solitaire 
	for(int i = 0; i < size; i++)
    {
		for(int j = 0; j < size; j++)
        {
			if(count[j] == 0 || (count[j] > 0 && decks[j][count[j] - 1] >= arr[i]))
            {
				decks[j][count[j]] = arr[i];
				count[j]++;
				break;
			}
		}
	}
    //setting up initial stage
	min = decks[0][count[0] - 1];
	pickedRow = 0;
    //check for the minimum value number from the top-most elements in each pile
    //and popping that least element in sorted array list
	for(int i = 0; i < size; i++)
    {
		for(int j = 0; j < size; j++)
        {
			if(count[j] > 0 && decks[j][count[j] - 1] < min){
				min = decks[j][count[j] - 1];
				pickedRow = j;
			}
		}
		sortedArr[i] = min;
		count[pickedRow]--;
 
		for(int j = 0; j < size; j++)
			if(count[j] > 0)
            {
				min = decks[j][count[j] - 1];
				pickedRow = j;
				break;
			}
	}
    //freeing up the allocated memory
	free(count);
	free(decks);
 
	return sortedArr;
}
 
int main (void) //(int argC,char* argV[])
{
	int *arr, *sortedArr;
    int sizeOfarray;
    
    printf("Enter the size of array: ");
    scanf("%d", &sizeOfarray);
    //dynamic mermory allocation to array
    arr = (int*)malloc((sizeOfarray) * sizeof(int));
    //array input
    printf("Enter %d elements of array (each seperated by a space): ", sizeOfarray);
    for(int i = 0; i < sizeOfarray; i++)
    {
        scanf("%d", &arr[i]);
    }

    //function call
	sortedArr = patienceSort(arr, sizeOfarray);
    printf("The sorted array is: ");
    //printing the sorted array
	for(int i = 0; i < sizeOfarray; i++)
    {
		printf("%d ", sortedArr[i]);
    }
    free(arr);
}
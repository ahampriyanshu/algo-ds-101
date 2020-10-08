/*
* Contributor: Jean Choi
* Minimum-Sum Descent
*
* Some positive integers are arranged in an equilateral triangle
* with n numbers in its base like the one shown in the figure below
* for n = 4.
*
* This program finds the  the smallest sum in a descent 
* from the triangle apex to its base through a sequence 
* of adjacent numbers (shown in the figure by dashes).
*
*           -2-
*       -5-      4
*    -1-     4       7
* 8     -6-      9      6
*
*/

#include <stdlib.h>
#include <stdio.h>

/*
* Finds the minimum between two integers
*/
int minimum(int a, int b){
  return (a < b) ? a : b;
}

/*
* Tabular Solution for created pyramid
*/
int tabular(int ** arr,  int n){
  for(int r = n; r >= 0; r--){
    for(int c = 0; c <= r; c++){
      if(r == n)
        arr[r][c] = arr[r][c];
      else
        arr[r][c] = arr[r][c] + minimum(arr[r+1][c], arr[r+1][c+1]);
    }
  }
  return arr[0][0];
}

int main(){
  //get number of levels in pyramid
  int levels;
  printf("Enter number of levels: ");
  scanf("%d", &levels);

  //allocate pyramid[][]
  int **pyramid;
  pyramid = malloc(levels * sizeof *pyramid);
  for (int i=0; i < levels; i++) {
    pyramid[i] = malloc(levels * sizeof *pyramid[i]);
  }

  //get values for pyramid[][]
  printf("Please only enter positive integers\n");
  for(int r = 0; r <= levels-1; r++) {
    printf("Enter %d items for level %d: ", r+1, r);
    for(int c = 0; c <= r; c++) {
      scanf("%d", &pyramid[r][c]);
    }
  }

  //print pyramid[][]
  printf("Here's the pyramid: \n");
  for (int r = 0; r < levels; r++){
    for (int c = 0; c <= r; c++){
      printf("%d ", pyramid[r][c]);
    }
    printf("\n");
  }
  printf("Minimum-Sum Descent for created pyramid (Tabular): %d\n", tabular(pyramid, levels-1));


  // deallocate the array
  for (int i=0; i<levels; i++) {
    free(pyramid[i]);
  }
  free(pyramid);
  return 0;
}

#include <stdio.h>
#include <stdlib.h> 

int CntSum(int arr[], int N, int required_sum) 
{ 
    int t[N+1][required_sum+1] , i ,j ;
    for(i = 0 ; i < N+1;i++)
        t[i][0] = 1;
    for(i = 1 ; i < required_sum+1;i++)
        t[0][i] = 0;
    for(i = 1; i < N+1;i++)
    {
        for(j = 1 ; j < required_sum+1;j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]]+t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[N][required_sum]; 
} 
int main() 
{ 
    int N , i;
    printf("Enter Size of Array :- \n");
    scanf("%d",&N);
    int A[N];
    printf("Enter Array Elements :- \n");
    for(i = 0 ; i< N;i++)
        scanf("%d",&A[i]);
    printf("Enter Target Sum :- \n");
    int X;
    scanf("%d",&X);
    long int ans = CntSum(A , N , X);
    printf("Count = %ld\n", ans);
  
    return 0; 
} 
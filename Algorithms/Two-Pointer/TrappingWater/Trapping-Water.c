#include<stdio.h>
#include<stdlib.h> 
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int maxWater(int arr[], int n)
{
     
    
   
    int ans = 0;
     
    for (int i = 1; i < n-1; i++) {
         
        int left = arr[i];
        for (int j=0; j<i; j++)
           left = MAX(left, arr[j]);
         
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = MAX(right, arr[j]);
        
       ans = ans + (MIN(left, right) - arr[i]);  
    }
 
    return ans;
}
 
int main()
{
    int q;
    printf("how long is your array ?");
    scanf("%d", &q);
    int arr[q];
    printf("input array one by one now");
    for (int i=0;i<q;i++)
    {
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
     
    printf("required answer is : %d", maxWater(arr, n));
     
    return 0;
}

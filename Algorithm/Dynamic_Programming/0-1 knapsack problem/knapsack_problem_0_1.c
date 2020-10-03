#include<stdio.h>

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int main()
{
    int n,sum;
    //n is no. of items and sum is total sum we required

    scanf("%d %d",&n,&sum);
    
    //declare weight array and value array
    int weight[n],value[n];

    //assigning value to weight array and value array
    for(int i=0;i<n;i++)
     scanf("%d",&weight[i]);

    for(int i=0;i<n;i++)
     scanf("%d",&value[i]); 
    
    //solving using top-down approach
    int dp[n+1][sum+1];
    
    //initalize left coloumn and top row to zero 
     for(int i=0;i<n+1;i++)
      dp[i][0]=0;

      for(int i=0;i<sum+1;i++)
       dp[0][i]=0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
         {
             if(weight[i-1]<=j)
               dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
                 
             else
              dp[i][j]=dp[i-1][j];
                  
         } 
    }
    
    //min value require to fill our knapsack is
     printf("%d \n",dp[n][sum]);   
}

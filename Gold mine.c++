#include<bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100; 
  
// Returns maximum amount of gold that can be collected 

// allowed moves are right, right-up and right-down 
int getMaxGold(int gold[][MAX], int n, int m) 
{ 
    // Create a table for storing intermediate results 

    int goldTable[n][m]; 
    memset(goldTable, 0, sizeof(goldTable)); 
  
    for (int col=n-1; col>=0; col--) 
    { 
        for (int row=0; row<m; row++) 
        { 
            // Gold collected  on the right(->) 
            int right = (col==n-1)? 0: goldTable[row][col+1]; 
  
            // Gold collected on  diagnolly up 
            int right_up = (row==0 || col==n-1)? 0:goldTable[row-1][col+1]; 
  
            // Gold collected on  to diagnolly down  
            int right_down = (row==m-1 || col==n-1)? 0: goldTable[row+1][col+1]; 
  
            // Max gold collected  
            
            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down)); 
                                                      
        } 
    } 
  
    // The max amount of gold collected will be the max 
    // value in first column of all rows 
    int res = goldTable[0][0]; 
    for (int i=1; i<m; i++) 
        res = max(res, goldTable[i][0]); 
    return res; 
} 
  
int main() 
{   
    int row,col;
    
    //enter  the size of matrix
    cin>>row>>col;
   
   int gold[MAX][MAX];
   
  for(int i=0;i<row;i++)
   for(int j=0;j<col;j++)
    cin>>gold[i][j];
    cout << getMaxGold(gold, row, col); 
    return 0; 
} 

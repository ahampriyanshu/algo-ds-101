#include <bits/stdc++.h> 
using namespace std; 
  
void printGolomb(int n) 
{ 
    int dp[n + 1]; 
    dp[1] = 1; 
    cout << dp[1] << " "; 
    for (int i = 2; i <= n; i++)  
    { 
        dp[i] = 1 + dp[i - dp[dp[i - 1]]]; 
        cout << dp[i] << " "; 
    } 
} 
int main() 
{ 
    int n;
    cin>>n;
  
    printGolomb(n); 
    return 0; 
} 

I/P: n=9
O/P: 1 2 2 3 3 4 4 4 5

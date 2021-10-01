#include<bits/stdc++.h> 
using namespace std;

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int lcs(string X, string Y, int m, int n); 

int shortestSuperSequence(string X, string Y) 
{
    int m = X.length();
    int n = Y.length(); 
    int l = lcs(X, Y, m, n); 

    return (m + n - l); 
} 

int lcs(string X,string Y,int m,int n) 
{ 
    int dp[m+1][n+1]; 
    int i,j;

    for(i=0;i<=m;i++) 
    {
        for(j=0;j<=n;j++) 
        { 
            if(i == 0 || j == 0) 
                dp[i][j] = 0;
            else if(X[i-1] == Y[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1; 
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
        }
    } 
    return dp[m][n]; 
} 

int main() 
{ 
    string s1,s2; 
    cout<<"Enter the first string :"<<"\n"; 
    cin>>s1; 
    cout<<"\nEnter the second string :"<<"\n";
    cin>>s2;
    cout<<"\nLength of the shortest common supersequence is "<<shortestSuperSequence(s1,s2); 
          
    return 0; 
} 
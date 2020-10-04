

//DP - LCS
  // Tabulation

#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int LCS(string X,string Y,int n,int m)
{  
    for(int i=0;i<n+1;i++)
    {
      for(int j=0;j<m+1;j++)
      {
         if(i==0 || j==0)
            t[i][j]=0;
    
         else if(X[i-1]==Y[j-1])
             t[i][j]=1+t[i-1][j-1];
             
         else
         t[i][j] = max(t[i-1][j],t[i][j-1]);
      }
    }
  return t[n][m];
}
int SCS(string X,string Y,int n,int m)
{
	return m+n-LCS(X,Y,X.length(),Y.length());
}
int main()
{
    string X,Y;
    cout<<"Enter first and second string : "<<endl;
    cin>>X>>Y;
   // memset(t,-1,sizeof(t));
    cout<<"Shortest common subsequence between two string is "<<SCS(X,Y,X.length(),Y.length())<<endl;
    return 0;
}

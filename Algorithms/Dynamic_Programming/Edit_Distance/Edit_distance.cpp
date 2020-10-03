/*
author-yogesh kansal
problem :- The edit distance between two strings is the minimum number of operations (insertions, deletions, and
substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings.
Edit distance has applications, for example, in computational biology, natural language processing, and spell
checking. Your goal in this problem is to compute the edit distance between two strings

Overall time complexity:- O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	string s1,s2;
	cout<<"enter string1:- ";
	cin>>s1;
	cout<<"\nenter string2:- ";
	cin>>s2;
	
	int n=s1.length()+1,m=s2.length()+1,i,j;
	int dp[n][m];
	for(i=0;i<n;i++)
	dp[i][0]=i;
	for(i=0;i<m;i++)
	dp[0][i]=i;
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		}
	}
	cout<<"\nEditable distance is:- ";
	cout<<dp[n-1][m-1];


	return 0;
}

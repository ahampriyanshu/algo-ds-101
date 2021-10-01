/*
	Author-yogesh kansal

problem statement:
		Given two sequences ?? = (a1, a2, . . . , am) and ?? = (b1, b2, . . . , bn),
 		find the length of their longest common subsequence'
 
time complexity :- O(m*n)
space complexity :- O(m*n)
*/

#include <stdio.h>
#define M 1000000007LL
#define mod 998244253LL
#define ll long long int
#define vi vector<int>

int max(int a,int b) {
	if(a>b)
		return a;
	else
		return b;
}

int main() {
	int n,m,i,j;
	
	printf("enter length of 1st subsequrnce:- ");
	scanf("%d",&n);
	int a[n];
	printf("\nenter sequence:- ");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
	printf("\nenter length of 2nd sequence:- ");
	scanf("%d",&m);
	int b[m];
	printf("\nenter sequence:- ");
	for(i=0;i<m;i++) scanf("%d",&b[i]);
	
	int dp[n+1][m+1];
	for(i=0;i<=n;i++)
	dp[i][0]=0;
	for(i=0;i<=m;i++)
	dp[0][i]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			if(a[i-1]==b[j-1])
			dp[i][j]+=1;
		}
	}
	printf("\nlength of longest common subsequence is:- ");
	printf("%d",dp[n][m]);
	return 0;
}

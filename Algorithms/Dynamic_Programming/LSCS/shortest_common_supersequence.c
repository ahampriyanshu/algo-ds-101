#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int sol(char* s1,char* s2,int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        dp[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
	char s1[101],s2[101];
	scanf("%s",&s1);
	scanf("%s",&s2);
	
//	printf("%s %s\n",s1,s2);
	int n=strlen(s1),m=strlen(s2);
	int ans=sol(s1,s2,n,m);
	printf("%d\n",n+m-ans);
    }
	return 0;
}

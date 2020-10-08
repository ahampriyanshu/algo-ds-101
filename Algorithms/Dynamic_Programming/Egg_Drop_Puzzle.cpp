#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,k;
	    cin>>k>>n;
	    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
	    for(int i=1;i<=k;i++)
	    {
	        dp[1][i]=1;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        dp[i][1]=i;
	    }
	    
	    for(int i=2;i<=n;i++)
	    {
	        for(int j=2;j<=k;j++)
	        {
	            int res;
	            dp[i][j]=INT_MAX;
	             for(int k=1;k<=i;k++)
	             {
	                res=1+max(dp[k-1][j-1],dp[i-k][j]);
	                if(res<dp[i][j])
	                {
	                    dp[i][j]=res;
	                }
	             }
	        }
	    }
	    cout<<dp[n][k]<<endl;
	}
	return 0;
}
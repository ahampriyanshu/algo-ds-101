#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define endl "\n"
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    string s1,s2,s3;
    cin>>s1>>s2>>s3;  // take input of three strings

    // Find the length of the three strings
    int n = s1.length(), m = s2.length(), l = s3.length();

    // Finding the lcs length

    int dp[n+1][m+1][l+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            for(int k=0; k<=l; k++)
            {
                if(i==0 || j==0 || k==0)
                    dp[i][j][k] = 0;
                else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    }

    int length_of_lcs = dp[n][m][l];     // Length of LCS of the 3 strings

    int i=n, j=m, k=l;

    string ans="";   // Initializing lcs string

    while(i>0 && j>0 && k>0)
    {
        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])   // If current character in s1, s2, and s3 are same, then current character is part of LCS 
        {
            ans+=s1[i-1];
            i--;
            j--;
            k--;
        }
        // If not same, then find the larger of the three and go in the direction of larger value 
        else if(dp[i-1][j][k] > dp[i][j-1][k] || dp[i-1][j][k] > dp[i][j][k-1])
            i--;
        else if(dp[i][j-1][k] > dp[i-1][j][k] || dp[i][j-1][k] > dp[i][j][k-1])
            j--;
        else
            k--;
    }

    // We have to reverse the lcs string because we
    // put characters in the lcs string from the last
    reverse(ans.begin(), ans.end());

    cout<<"The longest common subsequence is: ";

    cout<<ans<<endl;
 
    return 0;
   
}
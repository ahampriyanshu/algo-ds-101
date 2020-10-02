#include <bits/stdc++.h>

using namespace std;
int LCS(string s1, string s2){//function to get the longest common subsequence
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));//table of dp for finding length of longest subsequence
    for(int i = 1; i<=s1.length(); i++){
        for(int j = 1; j<= s2.length(); j++){
            if(s1[i-1] == s2[j-1])//if letter match in both string the following line to be used
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];//length of longest common subsequence here
}
int main()
{
    string s1, s2;
    cin>>s1;
    cin>> s2;
    int res = LCS(s1,s2);
    cout<< res<<endl;
    return 0;
}

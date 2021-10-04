#include<bits/stdc++.h>
using namespace std;


int nthTribonacci(int n){

    ////create a dp array of size n+1
    int dp[n+1];
    for(int i = 0; i <= n; i++){
      //since first three elements are 0, 0 and 1
      //so we can cleverly write dp[i] = i/2
      //otherwise, the sum of preceeding three values is the ith Tribonacci
      dp[i] = (i < 3 ? i/2 : dp[i-1] + dp[i-2] + dp[i-3]);
    }
    return dp[n];
}
int main(){

    //read input value of n
    int n;
    cin >> n;
    
    //print the corresponding output
    cout << nthTribonacci(n) << endl;
}
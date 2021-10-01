#include <bits/stdc++.h>

using namespace std;

/* 
Given an array of distinct posotive integers,find the largest subset such that every pair(a1,a2)
of elements in this subset satisfies
a1 % a2 = 0 or a2 % a1 = 0

Note - In case of multiple sych solutions return any subset.

Example 1: 
Input : [1 , 2 , 3]
Output : [1 , 2] or [1 , 3]

Example 2:
Input : [1 , 2 , 4 , 8]
Output : [1 , 2 , 4 , 8]
*/

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
    int n = nums.size();
    vector<int>ans;
    int max = 1;
    sort(nums.begin(),nums.end());
    vector<int>dp(n+1,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]%nums[j]==0&&1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
                if(max<dp[i])
                {
                    max=dp[i];
                }
            }
        }
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==max&&(prev%nums[i]==0||prev==-1)){
                ans.push_back(nums[i]);
                max-=1;
                prev=nums[i];
            }
        }
        return ans;
    }
}

int main()
{
    int n;
	cout << "array size : ";
	cin >> n;
	vector<int> arr(n);
	cout << "array element :\n";
    for(int i=0;i<n;i++)
    {
	    cin>>arr[i];
    }
    cout << largestDivisibleSubset(arr) << endl;
    return 0;
}

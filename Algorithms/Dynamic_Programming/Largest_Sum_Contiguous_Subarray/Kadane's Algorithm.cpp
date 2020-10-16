#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    vector<int> v(n,0);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    int sum=INT_MIN;
	    int maxSum=INT_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(sum>0)
	        {
	            sum+=v[i];
	        }
	        else
	        {
	            sum=v[i];
	        }
	        maxSum=max(sum,maxSum);
	    }
	    cout<<maxSum<<endl;
	}
	return 0;
}
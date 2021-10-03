#include<bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target)
{
    int n=mat.size();
    int m=mat[0].size();
    int l=0,h=n;
    int mid;
    while(l<h)
    {
        mid=l+(h-l)/2;
        if(target>=mat[mid][0] && target <=mat[mid][m-1])
            break;
        else if(target>=mat[mid][m-1])
            l=mid+1;
        else h=mid;
    }
    
    
    l=0,h=m;
    while(l<h)
    {
        int x=l+(h-l)/2;
        
            if(mat[mid][x]==target)
                return true;
        if(mat[mid][x]<target)
            l=x+1;
        else 
            h=x;
    }
    return false;
}
int main()
{
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>>mat(n,vector<int>(m));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>mat[i][j];

    if(searchMatrix(mat,target))
     cout<<"ELEMENT FOUND";
     else
     cout<<"ELEMENT NOT FOUND";
     return 0;

}
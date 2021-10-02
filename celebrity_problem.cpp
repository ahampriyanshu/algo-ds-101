#include<iostream>
#include<vector>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
{
    int c=-1,t=0;
    for(int i=0;i<M.size();++i)
    {
        for(int j=0;j<M.size();++j)
        {
            if(i!=j)
            {
                if(M[j][i]==1 && M[i][j]==0)
                {
                    t++;
                }
            }
        }
        if(t==M.size()-1)
        {
            c=i;
        }
        t=0;
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>v[i][j];
        }
    }
    cout<<celebrity(v,n)<<endl;
}
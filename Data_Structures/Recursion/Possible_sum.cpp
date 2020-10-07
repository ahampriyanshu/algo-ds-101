#include <bits/stdc++.h>
 
#define pb push_back
#define MAXN (int)1e5+100
 
using namespace std;
 
int n, s, x[30];
vector<char>ans;
bool rec(int pos, int sum)
{
    if(pos==n)
    {
        if(sum==s)return true;
        return false;
    }
     
    if(rec(pos+1, sum+x[pos])){ans.pb('+');return true;}
    if(rec(pos+1, sum-x[pos])){ans.pb('-');return true;}
}

int main()
{
    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
    }
     
    rec(1, x[0]);
    reverse(ans.begin(), ans.end());
    if(!ans.empty())
    {
        cout<<x[0];
        for(int i=1; i<n; i++)
        {
            cout<<ans[i-1]<<x[i];
        }
        cout<<'='<<s;
    }
    else cout<<"No solution";
     
}

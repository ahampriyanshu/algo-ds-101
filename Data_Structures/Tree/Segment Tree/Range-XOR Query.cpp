/*
PROBLEM LINK :- https://cses.fi/problemset/task/1650/ 
sOLUTIN BY:Ashutosh
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void build(ll a[],ll tl,ll tr,ll dp[],ll v)
{
    if(tl==tr)dp[v]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(a,tl,tm,dp,2*v);
        build(a,tm+1,tr,dp,2*v+1);
        dp[v]=(dp[2*v]^dp[2*v+1]);
    }
} 
ll xor_value(ll v,ll tl,ll tr,ll l,ll r,ll dp[])
{
    if(l>r)return 0;
    if(tl==l&&tr==r)return dp[v];
    ll tm=(tl+tr)/2;
    return (xor_value(v*2,tl,tm,l,min(r,tm),dp)^xor_value(v*2+1,tm+1,tr,max(l,tm+1),r,dp));
} 
void update(ll v,ll tl,ll tr,ll pos,ll value,ll dp[],ll a[])
{
    if(tl==tr)dp[v]=value;
    else{
        ll tm=(tl+tr)/2;
        if(pos<=tm)update(2*v,tl,tm,pos,value,dp,a);
        else update(2*v+1,tm+1,tr,pos,value,dp,a);
        dp[v]=min(dp[2*v],dp[2*v+1]);
    }
}
int main()
{   
     ll n,q; cin>>n>>q; ll a[n+10],i,dp[4*n+10],tl,tr,v;
     for(i=0;i<n;i++)cin>>a[i]; tl=0; tr=n-1; v=1; memset(dp,0,sizeof(dp));
     build(a,tl,tr,dp,v);
     while(q--)
     {
        ll l,r,x; cin>>l>>r; tl=0; tr=n-1; v=1;
        
        cout<<xor_value(v,tl,tr,l-1,r-1,dp)<<"\n";
     }
}


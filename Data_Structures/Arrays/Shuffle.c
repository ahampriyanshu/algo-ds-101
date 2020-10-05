/*
You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.
You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.
Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.
*/

#include <iostream>
#include<stdio.h> 
#include <bits/stdc++.h> 
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include<utility>
using namespace std;
#define ll long long
#define len length()
#define vi vector<int>
#define vl vector<ll>

#define fr(i,n) for(ll i=0;i<n;i++)
ll max(ll i,ll j){
    return i>j?i:j;
}
 
 
int main(){
    
int t; 
//t=1;
cin>>t;    
while(t--){

ll n,x,m; cin>>n>>x>>m; 
ll mx=x, mn=x;

while(m--){
    ll l,r;
    cin>>l>>r;
    
    if(mn>=l&&mn<=r || mx>=l&&mx<=r){
        
        mn=min(mn,l); mx=max(mx,r);
        
    }
    
    
}
ll ans=(mx-mn)+1;
cout<<ans<<endl;
  
}
 
}

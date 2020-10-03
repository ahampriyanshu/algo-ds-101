/*
You are given two arrays a and b both consisting of n positive (greater than zero) integers. You are also given an integer k.
In one move, you can choose two indices i and j (1≤i,j≤n) and swap ai and bj (i.e. ai becomes bj and vice versa). Note that i and j can be equal or different (in particular, swap a2 with b2 or swap a3 and b9 both are acceptable moves).
Your task is to find the maximum possible sum you can obtain in the array a if you can do no more than (i.e. at most) k such moves (swaps).
You have to answer t independent test cases.
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

int main(){
    
int t; cin>>t;
    
while(t--){
ll n,k; cin>>n>>k;
 
vl a(n,0),b(n,0);
fr(i,n){
    cin>>a[i];
}
 
fr(i,n){
    cin>>b[i];
}
 
sort(a.begin(),a.end());
sort(b.begin(),b.end(),greater<int>());
ll s=0,ans=0;
ll j=0;
fr(i,n){
    if(s<k){
       ll mx=max(a[i],b[j]);
       ans+=mx;
       if(mx==b[j]){
           j++;
           s++;
       }
    }
    else{
        ans+=a[i];
    }
}
 
cout<<ans<<endl;
}
 
}

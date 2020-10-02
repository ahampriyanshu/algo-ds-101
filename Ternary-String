/*
You are given a string s such that each its character is either 1, 2, or 3. 
You have to choose the shortest contiguous substring of s such that it contains each of these three characters at least once.
A contiguous substring of string s is a string that can be obtained from s
by removing some (possibly zero) characters from the beginning of s 
and some (possibly zero) characters from the end of s.
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
    
ll t; cin>>t;
while(t--){
string s;
cin>>s;
ll l=0;
 
ll x1 =-1,x2=-1,x3=-1;
ll ans=INT_MAX;
fr(i,s.len){
    
    {
          if(s[i]=='1') x1=i;
      
           if(s[i]=='2') x2=i;
           
           if(s[i]=='3') x3=i;
           
           if(x1!=-1&&x2!=-1&&x3!=-1){
               l=(max(x1,max(x2,x3))-min(x1,min(x2,x3)));
               ans=min(ans,l+1);
               
           }
                  
    }    
}
 
if(ans==INT_MAX) ans=0;
cout<<ans<<endl;
 
}
return 0;
}

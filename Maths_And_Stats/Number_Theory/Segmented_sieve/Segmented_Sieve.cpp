#include<bits/stdc++.h>
using namespace std;

vector<int>* sieve()
{
   vector<int>* s;
   bool isPrime[INT_MAX+1];
   memset(isPrime,true,sizeof(isPrime))
   isPrime[0] = false;
   isPrime[1] = false;
   for(int i=2; i*i<=INT_MAX;i++)
   {  
      if(isPrime[i])
      {
        for(int p=i*i; p<=INT_MAX; p+=i)
           isPrime[p]=false;
        
      }     
  }
  
  for(int i=0; i<=INT_MAX; i++){
    if(isPrime[i])
      s.push_back;
  } 
  return s; 
  }
  
  
  void Print_prime(long long l, long long r, vector<int>*&s){
    bool isPrime[r-l+1];
    for(int i=0; s->at[i]*long(long(s->at[i]))<=r;i++){
      int p = s->at[i];
      long long base = (l/p)*p;
      if(base<l)
        base=base+p;
      for(int j = base; j<=r; j+=p)
       isPrime[j-l]=false;
       
     if(base==p)
       isPrime[j-l]=true;
   }
   for(int i=0; i<=r-l; i++){
     if(isPrime[i])
     cout << i+l << endl;
   }
  
  
  
  }
  
  
  
  int main(){
    vector<int>* s = sieve();
    long long l,r;
    cout << "enter two digits between which you want to find the prime number";
    cin>>l>>r;
    Print_prime(l,r,s);
    return 0;
  }

/*
Here are the limits for Question 2:
1. Factorial - [0 - 1000]
2. Exponentiation - base => [0 - 10^200], exponent => [0 - INT_MAX]
3. GCD - [1 - 10^200], [1 - 10^200]
*/

#include<iostream>
#include<cmath>
#include <chrono> 
#include <stdlib.h>     
#include <time.h>
#include <time.h> 
using namespace std::chrono; 
using namespace std;


string remove_zeroes(string a){
  int i = 0;
  int size = a.size();
  while(i<size && a[i]=='0'){
    i++;
  }
  if(i==size)
    i--;
  return a.substr(i, size-i);
}

// a bigger than b
string subtract(string a, string b){
  string res = "";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int l1 = a.size();
  int l2 = b.size();
  int i = 0;
  int c = 0;
  for(; i<l2; i++){
    if(c==0){
      if(a[i]<b[i]){
        c = 1;
        a[i] = (10+a[i]-b[i])+ '0';
      } else {
        a[i] = (a[i]-b[i])+ '0';
      }
    } else {
      if(a[i]<=b[i]){
        a[i] = (9+a[i]-b[i])+ '0';
      } else {
        c = 0;
        a[i] = (a[i]-b[i]-1)+ '0';
      }
    }
  }
  for(; i<l1 && c>0; i++){
    if(a[i]=='0')
      a[i] = '9';
    else{
      a[i] = a[i]-1;
      c = 0;
    }
  }
  reverse(a.begin(), a.end());
  a = remove_zeroes(a);
  return a;
}

string add(string a, string b){
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int l1 = a.length();
  int l2 = b.length();
  int i = 0;
  int carry = 0, sum = 0;
  string res = "";
  for(; i<l1 && i<l2; i++){
    sum = (a[i] - '0' +b[i]-'0') + carry;
    carry = sum/10;
    res += ('0'+ sum%10);
  }
  while(i<l1){
    sum = (a[i] - '0') + carry;
    carry = sum/10;
    res += ('0'+ sum%10);
    i++;
  }
  while(i<l2){
    sum = (b[i] - '0') + carry;
    carry = sum/10;
    res += ('0'+ sum%10);
    i++;
  }
  if(carry>0){
    string c = to_string(carry);
    reverse(c.begin(), c.end());
    res+=c;
  }
  reverse(res.begin(), res.end());
  return res;
}

string multiply(string a, int n) {
    reverse(a.begin(), a.end());
    int size = a.size();
    unsigned long int c = 0, num = n;
    for(int i = 0; i < size; i++){
        unsigned long int m = num*(a[i]-'0');
        m+=c;
        a[i] = ('0' + m%10);
        c = m/10;
    }
    if(c>0){
        string t = to_string(c);
        reverse(t.begin(), t.end());
        a+=t;
    }
    reverse(a.begin(), a.end());
    return a;
}

string addzeroes(string a, int n){
  for(int i = 0; i < n; i++){
    a+='0';
  }
  return a;
}

string multiply(string a, string b){
  int l1 = a.length();
  int l2 = b.length();
  if(l1>l2){
    for(int i = 0; i < l1-l2; i++){
      b = "0"+b;
    }
  } else if(l2>l1){
    for(int i = 0; i < l2-l1; i++){
      a = "0"+a;
    }
  }
  int l = a.length();
  if(l==0){
    return "0";
  } else if(l==1){
    int res = (a[0]-'0')*(b[0]-'0'); 
    return to_string(res);
  }
  string al = a.substr(0, l/2);
  string ar = a.substr(l/2);
  string bl = b.substr(0, l/2);
  string br = b.substr(l/2);
  string t1 = multiply(al,bl);
  string t3 = multiply(ar,br);
  string t2 = subtract(multiply(add(al, ar), add(bl, br)), add(t1,t3));
  int pow = l-l/2;
  string res = add(add(addzeroes(t1, 2*pow), addzeroes(t2, pow)), t3);
  return res;
}

// string mul(string a, string b){

// }

string exponentiation(string a, unsigned long long b){
  string res = "1";
  while(b>0){
    if(b%2){
      res = multiply(res, a);
      b--;
    } else {
      a = multiply(a,a);
      b/=2;
    }
  }
  return remove_zeroes(res);
}


bool great(string a, string b){
  if(a.size()>b.size())
    return true;
  else if(a.size()<b.size())
    return false;
  else{
    for(int i = 0; i<a.size(); i++){
      if(a[i]>b[i])
        return true;
      else if(a[i]<b[i])
        return false;
    }
    return true;
  }
}

bool equals(string a, string b){
  if(a.size()>b.size())
    return false;
  else if(a.size()<b.size())
    return false;
  else{
    for(int i = a.size(); i>-1; i--){
      if(a[i]>b[i] || a[i]<b[i])
        return false;
    }
    return true;
  }
}

string mod(string a, string b){
  while(a.size()>b.size()+1){
    int diff = a.size()-b.size()-1;
    string t = multiply(b,pow(10,diff%9));
    diff -= (diff%9);
    while(diff>=9){
      t = multiply(t,pow(10,9));
      diff-=9;
    }
    a = subtract(a, t);
  }
  while(great(a, b)){
    a = subtract(a, b);
  }
  return a;
}

string gcd(string a, string b){
  string m = mod(a,b);
  if(equals(m,"0")){
    return b;
  } else {
    return gcd(b, m);
  }
}

string factorial(int n){
  if(n<1)
        return "1";
    string res = "1";
    for(int i = 1; i <= n; i++){
        res = multiply(res, i);
    }
    return res;
}

int main(){
  int t;
  cin>>t;
  while(t>0){
    t--;
    string a, b;
    int n; 
    unsigned long long exp;
    int opt;
    cin>>opt;
    switch(opt){
      case 1:
      {
        cin>>a>>exp;
        cout<<exponentiation(a,exp)<<endl;
      }
      break;
      case 2:
      {
        cin>>a>>b;
        a = remove_zeroes(a);
        b = remove_zeroes(b);
        if(great(a,b))
          cout<<gcd(a,b)<<endl;
        else
          cout<<gcd(b,a)<<endl;
      }
      break;
      case 3:
        cin>>n;
        cout<<factorial(n)<<endl;
      break;
    }
  }
  return 0;
}

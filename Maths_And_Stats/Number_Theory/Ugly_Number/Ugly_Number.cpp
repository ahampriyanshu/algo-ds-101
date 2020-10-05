#include<iostream>
#include<cstdlib>
using namespace std;

bool check(long long no);

bool check(long long no){
  while(no%2==0){
    no=no/2;
  }
  while(no%3==0){
    no=no/3;
  }
  while(no%5==0){
    no=no/5;
  }
  if(no==1){
    return true;
  }else{
    return false;
  }
}

int main(){
  long long num=0;
  cin>>num;
  bool arr= check(num);
  if(arr){
    cout<<"Ugly Number";
  }else{
    cout<<"Not Ugly";
  }
  return 0;
}

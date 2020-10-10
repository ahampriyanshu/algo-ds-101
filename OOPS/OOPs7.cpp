//run-time polymorphism

//employ class and 3 sub class, ask user which class to print.
#include <bits/stdc++.h>
using namespace std;
class Emp{
public:
  virtual void print(){
    cout << "Emp class";
  }
};
class SDE : public Emp{
  void print(){
    cout << "SDE class";
  }
};
class Management : public Emp{
  virtual void print(){
    cout << "Management class";
  }
};

int main(int argc, char const *argv[]) {
  int n; cin>>n;
  if(n == 1){
    Emp *e = new SDE();
    e->print();
  }
  else if(n == 2){
    Emp *e = new Management();
    e->print();
  }
  return 0;
}

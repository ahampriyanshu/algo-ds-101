//virtual functions

//1. what happens when we create base object with derrived constructor.
#include <bits/stdc++.h>
using namespace std;
class Base{
public:
  virtual void print(){
    cout << "Base class";
  }
};

class Derrived : public Base{
public:
  void print(){
    cout << "Derrived class";
  }
};
// class ob;
// class ob = new class
// class ob = new class()

int main(int argc, char const *argv[]) {
  Base* b = new Derrived();
  b->print();
  return 0;
}

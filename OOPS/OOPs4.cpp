//return this pointer
#include <bits/stdc++.h>
using namespace std;
class OOPS{
public:
  OOPS& print(){
    cout << "Hello";
    return *this;
  }
};
int main(int argc, char const *argv[]) {
  OOPS a;
  a.print().print();
  return 0;
}

//1. use initiliser list
//2. make default, parapetrised, copy constructor
#include <bits/stdc++.h>
using namespace std;
class OOPS{
private:
  int x, y, z;
public:
  OOPS(): x(0), y(0){     //initiliser list with default constructor.
    z = 0;
  }

  OOPS(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
  }
  OOPS(const OOPS& toCpy){
    this->x = toCpy.x;
    this->y = toCpy.y;
    this->z = toCpy.z;
  }
  print(){
    cout << x << " " << y << " " << z << endl;
  }
};
int main(int argc, char const *argv[]) {
  OOPS ob1;  //default constructor.
  ob1.print();
  OOPS ob2(2,3,4); //use parametrised constructor.
  ob2.print();
  OOPS ob3(ob1); // copy constructor.
  ob3.print();
  return 0;
}

//check if ob1(ob) and ob1 = ob not same.
//ob1(ob) is a copy constructor to initilise a object.
//where as ob1 = ob, is use to assign diff set of values to already assigned object.
#include <bits/stdc++.h>
using namespace std;
class OOPS{
public:
  int* arr;
  OOPS(){
    arr = new int[4];
    for(int i = 0; i < 4; i++){
      arr[i] = 5;
    }
  }
  void print(){
    for(int i = 0; i < 4; i++){
      cout << arr[i] << " ";
    }cout << "\n";
  }
  void change(int x){
      arr[0] = x;
  }
};
int main(int argc, char const *argv[]) {
  OOPS ob; // 5
  OOPS ob2 = ob; //5

  OOPS ob3;
  ob3 = ob; //5

  ob.change(3); // 3 5 5 5
  ob.print();
  ob2.print();
  ob3.print();

  return 0;
}

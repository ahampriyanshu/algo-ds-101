//1. make a dynamic memory to see deep and shallow copy
#include <bits/stdc++.h>
using namespace std;
class OOPS{
private:
  int* arr;
public:
  OOPS(){
    arr = new int[10];
  }
  OOPS(const OOPS& ob){ // make a deep copy
    arr = new int[10];
    for(int i = 0; i < 10; i++){
      this->arr[i] = ob.arr[i];
    }
  }
  void set(int x){
    for(int i = 0; i <10; i++){
      arr[i] = x;
    }
  }
  void change(int x){
    for(int i = 0; i < 10; i++){
      arr[i] = x;
    }
  }
  void print(){
    for(int i = 0; i < 10; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};
int main(int argc, char const *argv[]) {
  OOPS ob;
  ob.set(3);
  OOPS ob1(ob); //ob1 all values should be 3.
  ob.change(5);
  ob1.print(); //even I'm changing ob values, but ob1 values will also be changed.(Shallow Copy)

  return 0;
}

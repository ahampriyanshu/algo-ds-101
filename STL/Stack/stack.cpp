#include <bits/stdc++.h>
using namespace std;
//Stack follows FILO
int main(int argc, char const *argv[]) {
  //make a stack.
  stack<int> s;

  //add item to stack
  s.push(1);

  //remove item from stack.
  s.pop();

  //find size of stack
  s.size();

  //find the top most item in stack.
  s.top();

  //check if stack is empty
  s.empty();
  return 0;
}

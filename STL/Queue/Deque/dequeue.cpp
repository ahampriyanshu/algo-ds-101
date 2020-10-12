#include <bits/stdc++.h>
using namespace std;
//Dequeue - stack + queue
int main(int argc, char const *argv[]) {
  deque<int> dq;

  //insertion
  dq.push_front(1);
  dq.push_back(1);
  dq.insert(it,val);
  dq.insert(it,freq,val);

  //delete item
  dq.pop_front(1);
  dq.pop_back(1);
  dq.erase(it);  //remove item by iterator.
  dq.erase(it, it1); //remove all items inbetween that iterators.

  return 0;
}

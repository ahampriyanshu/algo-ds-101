#include <bits/stdc++.h>
using namespace std;
//Heaps are implemenation of priority queue data structurs.
//we have 2 types of heap, Min-Heap and Max-Heap.


//C++ privide a inplace heap data structure for implemenation of heap.
int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,3,4,5,6};

  //make a vector a heap, C++ default heap is max heap.
  make_heap(v.begin(), v.end());

  //remove a element from heap.
  pop_heap(v.begin(), v.end());
  //note the although you have delete the item from heap but it's still in vector.

  //add item at heap.
  push_heap(v.begin(), v.end()); //if element is in vector but not in heap, it will add that item.

  //sort heap.
  sort_heap(v.begin(), v.end()); //uses heap_sort..

  //print the first element of heap.
  cout << heapp.front();

  return 0;
}

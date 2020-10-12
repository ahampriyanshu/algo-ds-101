//This is the code for learning all the functions of map in cpp STL.


// A map is a (key,value) pair of elements.

// ordered_map is implemented internally by red-black tree.
// unordered_map is implemented by hashing.

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {

  //create a map
  map<int,char> mp;

  ////add values to map.
  mp.insert({1,'a'});  // O(log(n)) time
  mp.insert({2,'b'});
  mp.insert({1,'a'});  //never contains duplicates for key(s)
  mp[4] = 'f';

  //make an iterator for map.
  map<int,char> ::iterator it = mp.begin();
  auto it = mp.begin();

  //find a value
  mp.find(3); // returns iterator to the item, else returns mp.end().

  //delete elements from map.
  mp.clear(); //clears all the elements, O(n) time
  auto it = mp.find('a');  //iterator to element with value 'a' , O(lg(n)) time
  mp.clear(it);   //deletes the element in the iterator  //O(1) time
  mp.clear(it1,it1+1);  //delete more than 1 element at a time.

  //find size of map.
  mp.size();   //O(1)

  //alternative to find if a element is present or not.
  mp.count(key);   //return 1 if present, 0 if not present.


  //binary search to map.
  auto it1 = lower_bound(mp.begin(), mp.end(), val);  //O(log(n))
  auto it2 = upper_bound(mp.begin(), mp.end(), val);  //O(log(n))

  //lower bound find the value " >= " the element
  //Upper bound find the value " > " the element


  //if lower_bound and upper_bound needed at the same time.
  auto it = equal_range(mp.begin(), mp.end(), val);
  it.first //will be same as lower_bound
  it.second //same as upper_bound

  //iterate over a map .
  for(auto it = mp.begin(); it != mp.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}



/*
Note -

Multimap and unordered_map have simpliar function with same syntax.

but with a difference -

    Multimap allows to insert duplicate elements,
    and mp.count() returns number of occurance of that value in map.

    unordered_map does'nt allows duplicates but it allows insertion, deletion, find in O(1) time.

*/

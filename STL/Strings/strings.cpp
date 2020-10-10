#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {

  //declare string
  string str;
  char ch[10];

  //getting input
  cin >> str;
  getline(cin, str);

  //adding something to string
  str += "bc";
  str.puch_back("de");
  str.append("fg");

  //copy string to other
  str2.copy(str1, length to copy, start position);

  //swap of 2 strings
  str1.swap(str2);

  //find a pattern in a string.
  str1.find("abc");

  //extract substring
  str1.substr(1,4);

  //lexographically compare of string.
  s1 > s2
  s1 < s2
  s1 == s2
  s1 >= s2
  s1 <= s2

  //replace a group of sub-string
  str.replace(start index, till index, "characters");

  //delete from string
  str.erase(it);  //it is the iterator
  str.erase(position);
  str.erase(position, no of items);
  return 0;
}

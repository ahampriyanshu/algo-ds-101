#include <iostream>
#include <map>
using namespace std;

int main (){
  map<char,int> hacktober;
                              //initializing number with char map
  hacktober['a']=10;
  hacktober['b']=20;
  hacktober['c']=30;
  hacktober['d']=40;
  
   map<char, int>::iterator it;
   
   for(it = hacktober.begin() ; it! = hacktober.end() ; ++it){   //iterating through the map
      cout << it->first << " => " << it->second << '\n';
   }
   
  return 0;
}

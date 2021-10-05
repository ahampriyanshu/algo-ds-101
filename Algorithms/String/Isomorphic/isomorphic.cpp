#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
// Find if strings 'X' and 'Y' are Isomorphic or not
bool isIsomorphic(string X, string Y)
{
    // if 'X' and 'Y' have different lengths, they cannot be isomorphic
    if (X.length() != Y.length()) {
        return false;
    }
 
    // use a map to store a mapping from characters of string 'X' to string 'Y'
    unordered_map<char, char> map;
 
    // use set to store a pool of already mapped characters
    unordered_set<char> set;
 
    for (int i = 0; i < X.length(); i++)
    {
        char x = X[i], y = Y[i];
 
        // if `x` is seen before
        if (map.find(x) != map.end())
        {
            // return false if the first occurrence of `x` is mapped to a
            // different character
            if (map[x] != y) {
                return false;
            }
        }
 
        // if `x` is seen for the first time (i.e., it isn't mapped yet)
        else {
            // return false if `y` is already mapped to some other char in 'X'
            if (set.find(y) != set.end()) {
                return false;
            }
 
            // map `y` to `x` and mark it as mapped
            map[x] = y;
            set.insert(y);
        }
    }
 
    return true;
}
 
int main()
{
    cout<<"Enter String X:";
    string X;
    cin>>X;
    cout<<"Enter String Y:";
    string Y;
    cin>>Y;
 
    if (isIsomorphic(X, Y)) {
        cout << X << " and " << Y << " are Isomorphic";
    }
    else {
        cout << X << " and " << Y << " are not Isomorphic";
    }
 
    return 0;
}





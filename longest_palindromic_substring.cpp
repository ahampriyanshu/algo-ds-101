#include<iostream>
#include <string> 
using namespace std;

string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
}
        
string LPS(string A) {
    int n = A.length();
    if (n == 0) 
       return "";
    string longest = A.substr(0, 1);    // a single char itself is a palindrome
    for (int i = 0; i < n-1; i++) {
        //for possible odd length palindrome-
        string p1 = expandAroundCenter(A, i, i);
        if (p1.length() > longest.length())
            longest = p1;
        //for possible even length palindrome-
        string p2 = expandAroundCenter(A, i, i+1);
        if (p2.length() > longest.length())
            longest = p2;
    }
    return longest;
}

int main() {
   string s;
   getline(cin, s);
   string answer = LPS(s);
   cout << answer;
   return 0;
}

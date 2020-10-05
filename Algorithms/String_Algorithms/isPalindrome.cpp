#include<bits/stdc++.h>

using namespace std;

// Check whether the string is palindrome or not considering
// only Alpha-Numeric Characters ignoring cases

int main() {
    string s;
    cin>>s;

    int l=0,r=s.size()-1;
    while(l<r) {
        while(!isalpha(s[l]) and !isdigit(s[l])) l++;
        while(!isalpha(s[r]) and !isdigit(s[r])) r--;

        if(l>=r) break;

        if(isupper(s[l])) s[l] = tolower(s[l]);
        if(isupper(s[r])) s[r] = tolower(s[r]);

        if(s[l]==s[r]) l++,r--;
        else break;
    }
    if(l<r) cout<<"It is not a Palindrome string\n";
    else cout<<"It is a Palindrome String\n";
    return 0;
}

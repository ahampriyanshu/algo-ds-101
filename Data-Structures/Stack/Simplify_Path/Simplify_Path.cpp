#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string simplifyPath(string path)
{
    stack<string> stk;
    string tmp;
    stringstream ss(path);
    while (getline(ss, tmp, '/'))
    {
        if (tmp == "" || tmp == ".")
            continue;
        if (tmp == ".." && !stk.empty())
            stk.pop();
        else if (tmp != "..")
            stk.push(tmp);
    }
    string res;
    while (!stk.empty())
    {
        res = "/" + stk.top() + res;
        stk.pop();
    }
    return res == "" ? "/" : res;
}

int main()
{
    string path;
    cout << "Enter a valid path for file: ";
    cin >> path;
    string res = simplifyPath(path);
    cout << res;
    return 0;
}
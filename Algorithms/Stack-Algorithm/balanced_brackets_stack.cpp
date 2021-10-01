#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' ) //push if opeening bracket is encountered
            s.push(str[i]);
        else
        {
            if(s.empty()) //if stack is empty return 0
                return 0;
            s.pop();// pop the last element in stack
        }
    }
    if(!s.empty()) // if still stack has some brackets remaining return 0
        return 0;
    return 1;
}


int main()
{
    string bracSeq = "(()";
    cout << isBalanced(bracSeq);
    return 0;
}

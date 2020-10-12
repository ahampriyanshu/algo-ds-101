/*Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid substring.
NOTE: Length of smallest the valid substring ( ) is 2.
Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a string S consisting only of ( and ).
Output
Print out the length of the longest valid substring.
Constraints
1 <= T <= 100
0 <   S  <= 110
Examples
Input
4
(()(
()()((
((()()())))
()(())(
Output
2
4
10
6
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        stack<int> s;
        s.push(-1);
        int result=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='(')
                s.push(i);
            else{
                s.pop();
                if(!s.empty())
                    result=max(result,(i-s.top()));
                else
                    s.push(i);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}

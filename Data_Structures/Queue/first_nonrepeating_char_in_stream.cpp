/*Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If no non repeating element is found print -1.
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.
Output:
For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when a character is added to the stream, if no such element is present print -1.
Constraints:
1 <= T <= 200
1 <= N <= 500
Example:
Input:
2
4
a a b c
3
a a c
Output:
a -1 b b
a -1 c
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> ch(n);
        for(int i=0;i<n;i++)
            cin>>ch[i];
        int freq[26];
        for(int i=0;i<n;i++)
            freq[i]=0;
        queue<char> q;
        for(int i=0;i<n;i++){
            freq[ch[i]-'a']++;
            q.push(ch[i]);
            while(!q.empty()){
                if(freq[q.front()-'a']>1)
                    q.pop();
                else{
                    cout<<q.front()<<" ";
                    break;
                }
            }
            if(q.empty())
                cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

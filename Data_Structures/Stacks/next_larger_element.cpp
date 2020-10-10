/*Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1
Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.
Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.
Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1
*/
#include<bits/stdc++.h>
using namespace std;
void nge(int a[],int n){
    stack<int> s;
    s.push(a[0]);
    for(int i=1;i<n;i++){
        if(s.empty()){
            s.push(a[i]);
            continue;
        }
        while(!s.empty() && s.top()<a[i]){
            cout<<s.top()<<"--->"<<a[i]<<endl;
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<"--->"<<"-1"<<endl;
        s.pop();
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        nge(a,n);
        cout<<endl;
    }
    return 0;
}

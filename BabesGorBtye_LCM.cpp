#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int lcm= (a/ __gcd(a,b))*b;
    cout<<lcm<<endl;
    return 0;
}




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int b, e, m;
    int power, res;
    cout<<"Enter the base value: ";
    cin>>b;
    cout<<"Enter the exponent value: ";
    cin>>e;
    cout<<"Enter the modulus value: ";
    cin>>m;
    power = pow(b,e);
    res = power % m;
    cout<<"The modular exponentiation value of given set of values is: "<<res;

    return 0;
}
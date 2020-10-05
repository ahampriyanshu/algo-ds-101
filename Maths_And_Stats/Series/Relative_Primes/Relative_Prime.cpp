#include<bits/stdc++.h>// this includes all the predefined libraries required in the program;
using namespace std;


int main()
{

    int num1,num2;
    //The value of two numbers is being entered below
    cin>>num1;
    cin>>num2;
    //we will use the _gcd function to find the gcd or hcf of the numbers that have been entered.
    int hcf;
    hcf=__gcd(num1,num2);
    if(hcf==1)
    cout<<"The numbers are relatively prime";
    else
    cout<<"The numbers are not relatively prime";
    return 0;

}
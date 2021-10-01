/*
    This is a code for armstrong number
    Code written by Manas Ranjan Swain
*/


#include <iostream>
#define ll long long int

using namespace std;

int main()
{
    //The number of test cases
    cout << "Enter the number of testcases" << endl;
    int t;
    cin >> t;
    while(t--){
        ll n,rem,ans=0;
        cout << "Enter a number" << endl;
        cin >> n;

        ll n1=n;
        while(n1>0){
            rem = n1%10;
            ans = ans + (rem*rem*rem);
            n1 = n1/10;
        }

        if(ans == n)
            cout << "The number " << n << " is an armstrong number" << endl;
        else
            cout << "The number " << n << " is not an armstrong number" << endl;
    }
}

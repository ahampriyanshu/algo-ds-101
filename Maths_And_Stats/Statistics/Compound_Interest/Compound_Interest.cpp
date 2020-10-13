//  Compound Interest  C.I. = P(1+R/100)^t
#include <bits/stdc++.h>
using namespace std;
// helper function
double compoundInterest(double p, double r, double t) {
    return p * pow( (1 + r/100), t );
}
// driver function
int main() {
    // variables are self-explanatory
    double principle;
    double rate;
    double time;

    cout<<"Enter the principle \n";
    cin>>principle;

    cout<<"Enter the rate\n";
    cin>>rate;

    cout<<"Enter the time";
    cin>>time;

    cout<<"The compound interest is: "<<compoundInterest(principle, rate, time);
    return 0;
}
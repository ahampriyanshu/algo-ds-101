// Program to find sum of n natural numbers

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum, a=1;
    cout << "Enter number of terms: ";
    cin >> n;
    sum = (n*(n+a))/2;
    cout << "The sum of first " << n << " natural numbers are: " << sum << endl;
    return 0;
}
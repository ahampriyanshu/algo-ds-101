#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    double sum = 0;

    cout.precision(12);
    cout << "Enter an n number of iterations: " << endl;
    cin >> n;
    cout << "Pi estimated at " << n << " iterations is: " << endl;

    int i = 0;
    while (i < n)
    {
        cout << i << " ";
        i++;
        sum = sum + 4 * (pow(-1.0, i) / ((2.0 * i) + 1));
        cout << sum << endl;
        cout << endl;
    }
    cout.precision(12);
    cout << sum << endl;
    cout << "The value of pi to " << n << " iterations is " << sum << endl;
    cout << "cmath library estimates Pi at " << M_PI << endl;
    return 0;

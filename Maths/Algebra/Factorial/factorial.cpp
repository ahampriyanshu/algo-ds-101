#include <iostream>
using namespace std;

int main() {
    int n; // declaration of number
    long double factorial = 1.0;

    cout << "Enter a positive integer: ";
    cin >> n;           // enter the number

    if (n < 0)          // if the number is less than 0 then factorial of negative number does not exist
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;         //calculation of factorial
        }
        cout << "Factorial of " << n << " = " << factorial;         //print the factorial
    }

    return 0;
}

#include <bits/stdc++.h>


// C++ program to count divisible pairs.
using namespace std;

int DivisiblePairsCount(vector<int> v, int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i) {                             // Iterating through each pair.
       for (int j = i+1; j < n; ++j) {
            if (v[i] % v[j] == 0 || v[j] % v[i] == 0)              // Checking for problem condition.
              res++;
       }
    }
    return res;
}

int main()
{
    int n;

    cout << "Enter Size of the Array:  ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter Array Elements:  ";
    for (auto &i : v) {                  // Vector Input
        cin >> i;
    }

    cout << "Number of Divisible Pairs:  ";

    cout << DivisiblePairsCount(v, n);


    return 0;
}

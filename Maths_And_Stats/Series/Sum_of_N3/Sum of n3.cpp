/*Sum of n³*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	cin >> n; // Input

	/*We have a mathematical formula according to which
	sum of cubes of first n natural numbers
	is given by ((n*(n+1))/2)*((n*(n+1))/2)*/

	int ans = ((n*(n+1))/2)*((n*(n+1))/2);

	cout << ans << endl; // output

	return 0;
}
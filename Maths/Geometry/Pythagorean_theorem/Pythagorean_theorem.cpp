#include<bits/stdc++.h>
using namespace std;

int main() {

	double sides[3];
	cout << "Enter the sides of triangle: ";
	cin >> sides[0] >> sides[1] >> sides[2];

	sort(sides, sides + 3);

	if((sides[0] * sides[0]) + (sides[1] * sides[1]) == sides[2] * sides[2]) {

		cout << "True, it is a right angled triangle as it follows Pythagorean Theorem (a^2 + b^2 = c^2)" << endl;

	}

	else {
		cout << "False, it is not a right angled triangle as it does not follow the Pythagorean Theorem" << endl;
	}

	return 0;
}
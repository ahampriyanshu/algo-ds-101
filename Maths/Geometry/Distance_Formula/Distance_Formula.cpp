#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double point_1[2];
	double point_2[2];
	cout << "Enter the co-ordinates of point 1: \n";
	cout << "x1: ";
	cin >> point_1[0];
	cout << "y1: ";
	cin >> point_1[1];

	cout << "Enter the co-ordinates of point 2: \n";
	cout << "x2: ";
	cin >> point_2[0];
	cout << "y2: ";
	cin >> point_2[1];

	double a_square;
	double b_square;

	a_square = pow((point_2[0] - point_1[0]), 2);
	b_square = pow((point_2[1] - point_1[1]), 2);

	cout << "The distance between both points is " << sqrt(a_square+b_square) << " units.\n";
}
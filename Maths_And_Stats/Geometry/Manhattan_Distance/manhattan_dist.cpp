#include<bits/stdc++.h>
using namespace std;

int manhattan_dist(int, int, int, int);

int main()
{
	int x1, x2, y1, y2, dist=0;
	cout << "Enter points of A: ";
	cin >> x1 >> y1;
	cout << "Enter points of B: ";
	cin >> x2 >> y2;
	dist = manhattan_dist(x1, x2, y1, y2);
	cout << "The Manhattan distance is: " << dist << endl;
	return 0;
}

int manhattan_dist(int a1, int a2, int b1, int b2)
{
	return (abs(a1-a2)+abs(b1-b2));
}

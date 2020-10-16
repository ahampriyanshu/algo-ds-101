CODE:
#include <iostream>
using namespace std;

int findAngle(int hour, int min)
{
	int h = (hour * 360) / 12 + (min * 360) / (12 * 60);
	int m = (min * 360) / (60);
	int angle = abs(h - m);
	if (angle > 180)
		angle = 360 - angle;

	return angle;
}
int main()
{
	int hour;
	int min;
  cin>>hour>>min;

	cout << findAngle(hour, min);

	return 0;
}

INPUT:hour=5, min=30
OUTPUT:15

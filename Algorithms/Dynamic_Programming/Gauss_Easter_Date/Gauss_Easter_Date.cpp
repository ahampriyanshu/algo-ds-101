#include <iostream>
using namespace std;

void gaussAlgorithm(int year, int *month, int *day);

int main()
{
	int year, easterMonth=3, easterDay=22;
	cout << "Enter a year for which you wish to find out date of Easter for: ";
	cin >> year; //input year
	cout << endl;
	gaussAlgorithm(year, &easterMonth, &easterDay); //calculate month and day
	cout << "Date of easter for year " << year << " is: " << ((easterMonth == 3) ? "March " : "April ") << easterDay << endl;
	char ch;
	cin >> ch; //wait for user input
	return 0;
}

void gaussAlgorithm(int year, int *month, int *day) //https://math.stackexchange.com/questions/896954/decoding-gauss-easter-algorithm
{
	int a, b, c, k, p, q, M, N, d, e;
	a = year%19;
	b = year%4;
	c = year%7;
	k = year/100;
	p = (13+8*k)/25; q = k/4;
	M = (15-p+k-q)%30;
	N = (4+k-q)%7;
	d = (19*a + M) %30;
	e = (2*b + 4*c + 6*d + N)%7;
	if((22+d+e) < 32)
	{
		*day=22+d+e;
	}
	else
	{
		*day=d+e-9;
		*month=4;
	}
	if(d==29 && e==6 && *month==4 && *day==26)
		*day=19;
	if(d==28 && e==6 && *month==4 && *day==25 && (11*M+11)%30 < 19)
		*day=18;
} //"It is not possible to present here the entire analysis that led to the above formula" -Gauss

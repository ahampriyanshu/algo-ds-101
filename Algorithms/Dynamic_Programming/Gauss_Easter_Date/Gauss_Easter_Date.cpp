#include <iostream>
using namespace std;

int main()
{
	int year, a, b, c, d, e, easterM=3, easterD=22, m=3;
	cout << "Enter a year for which you wish to find out date of Easter for: ";
	cin >> year;
	cout << endl;
	a=year%19; //calculating date of easter for given year using Gauss' Easter Algorithm
	b=((19*a)+24)%30;
	c=year%4;
	d=year%7;
	e=((6*b)+(2*c)+(4*d)+5)%7;
	int l = b+e;
	for(int i = 0; i<l; i++)
	{
		easterD++;
		if(m%2 == 1)
		{
			if(easterD > 31)
			{
				easterD=easterD-31;
				easterM++;
			}
		}
		else
		{
			if(easterD > 30)
			{
				easterD=easterD-30;
				easterM++;
			}
		}
		
	}
	cout << "Date of Easter for year " << year << " is: "; //printing results
	switch(easterM)
	{
		case 3: cout << "March "; break;
		case 4: cout << "April "; break;
		case 5: cout << "May "; break;
		case 6: cout << "June "; break;
	}
	cout << easterD << endl;
	char ch;
	cin >> ch; //wait for user input
	return 0;
}

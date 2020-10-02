#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
	{
	   return a;
	}

	return gcd(b, a % b); 
}

int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)
	{	
		cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
	}
	else{
		cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(b, a);
	}
	return 0;
}

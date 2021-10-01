// Implementing Euclid algorithm to find GCD

#include <bits/stdc++.h> 
using namespace std; 

// Finding GCD using Euclid algorithm by recursion
int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	
	return gcd(b % a, a);
}

//main function
int main()
{
	// taking input the required two numbers
	// whose gcd is to be calculated
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}

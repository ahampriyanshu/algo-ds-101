#include<bits/stdc++.h>
using namespace std;

void scalar_prod(int [], int [], int);

int main()
{
	int n, a[100], b[100];
	cout << "Enter size: ";
	cin >> n;
	
	cout << "Enter data of a: ";
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	cout << "Enter data of b: ";
	for(int i=0; i<n; i++)
		cin >> b[i];
		
	scalar_prod(a, b, n);
	
	return 0;
}

void scalar_prod(int x[], int y[], int num)
{
	int prod=0;
	for(int j=0; j<num; j++)
	{
		prod += x[j] * y[j];
	}
	
	cout << "Scalar product: " << prod << endl;
}

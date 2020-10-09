#include <bits/stdc++.h>
using namespace std;

int main()
{
	//input n: rows and m: columns
	int n, m;
	cin >> n >> m;

	//create array of size n*m and take input from the user
	int ar[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];

	//initialize count with 0 which keeps count of all submatrices having 1.
	int count = 0;


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			//if ar[i][j] = 0, continue;
			if (ar[i][j] == 0)
				continue;
			//calculate submtrices that end with index (i , j);
			//basically we look at the previous row, column and diagonal and then add 1 to it's minimum.
			else
				ar[i][j] = min({ar[i - 1][j], ar[i][j - 1], ar[i - 1][j - 1]}) + 1;
		}
	}

	//sum of the whole array to get final answer
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			count += ar[i][j];


	//print number of square submatrices containing all zeroes.
	cout << count << "\n";

	return 0;
}

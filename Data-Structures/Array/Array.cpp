#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	//number of elements as input
	cin >> n;
	int arr[n]; //initiallize array
	for(int i =0;i<n;i++)
	{
		cin >> arr[i]; // input the elements
	}
	/*for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";//traverse the array and print the elements
	}*/
	sort(arr, arr + n); //Here we sorted the arrray
	for (int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}

	return 0;
}

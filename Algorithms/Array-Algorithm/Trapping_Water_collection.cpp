#include<iostream>
using namespace std;


void rainwaterfun(int n, int a[])
{
	int left[n] = {0};
	int right[n] = {0};

	left[0] = a[0];
	for(int i =1; i<n; i++){
		left[i] = max(left[i-1],a[i]);
	}

	//right array
	right[n-1] = a[n-1];
	for(int i = n-2; i>=0; i--){
		right[i] = max(right[i+1], a[i]);
	}

int water = 0;
	for(int i =0; i<n; i++){
		water += min(left[i], right[i]) - a[i];
	}
	cout<<water;
}
int main(){
	int n;
	cin>>n;
	int a[n];

	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	rainwaterfun(n, a);
}
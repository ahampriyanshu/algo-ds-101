#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	
	cin>>n;						//size of the array
	int element;	
	cin>>element;		//element that have to searched
	int arr[n];
	for(int i=0;i<n;i++){				
		cin>>arr[i];					//taking array input
	}
	for(int i=0;i<n;i++){
		if(arr[i]==element){
			cout<<"YES"<<endl;			//doing linearly searching and prints "YES" if found else "NO"
			return 0;
		}
	}
	cout<<"NO"<<endl;
}
// C++ program to demonstrate functionality of unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	// Declaring umap to be of <string, int> type
	// key will be of string type and mapped value will
	// be of int type
	unordered_map<string, int> umap;

	// inserting values by using [] operator
	string s1, s2 ,s3;
	cin>>s1>>s2>>s3;
    
	int a,b,c;
	
	cin>>a>>b>>c;

	umap[s1] = a;
	umap[s2] = b;
	umap[s3] = c;

	// Traversing an unordered map
	for (auto x : umap)
	cout << x.first << " " << x.second << endl;

}
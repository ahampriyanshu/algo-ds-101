#include <bits/stdc++.h>
using namespace std;

vector <int> vector_product (vector <int>a, vector <int> b){
	if (a.size()!=3 || b.size()!=3){
		cout<<"Invalid INPUT"<<"\n";
		return {};
	}
	vector <int> ans(3);
	ans[0] = a[1]*b[2] - a[2]*b[1];
	ans[1] = a[2]*b[0] - a[0]*b[2];
	ans[2] = a[0]*b[1] - a[1]*b[0];
	return ans;
}

int main(){
	vector <int> a (3);
	vector <int> b (3);
	cout<<"Enter the coordinartes of First Vector"<<endl;
	cin>>a[0]>>a[1]>>a[2];
	cout<<"Enter the coordinartes of First Vector"<<endl;
	cin>>b[0]>>b[1]>>b[2];
	cout<<"Output is :"
	for (auto x:vector_product(a,b))
		cout<<x<<" ";
	cout<<endl;
	return 0;
}

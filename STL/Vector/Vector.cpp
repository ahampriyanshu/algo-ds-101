#include <bits/stdc++.h>
using namespace std;
//Vector are dyanmic arrays, internally they are normal C style arrays.
int main() {

	// initilise empty vector
	vector<int> empty_vec;  // {} ,empty vector

	//make a vector with default values
	vector<int> empty_vec = {12,23,45};  // {12,23,45}

	//make a vector with values from vector or array
	int arr[] = {1,2,3,4,5};
	vector<int> v1(arr,arr+n); //make a vector with array values
	vector<int> v2(v1.begin(), v1.end()); //make a new vector with old vector

	vector<int> v3(10,0);  //vector of size 10 with default value 0.

	//add a value to vector
	v.push_back(45);  //insert value at the vector at end.

	//remove value from vector
	v.pop_back();

	//insert at a specific position.
	v.insert(v.begin(), 101);  //v.insert(position, value)

	//print the value at ith position.
	cout << v.at(i);

	//insert at a specific position a number of times.
	v.insert(v.begin(), 10, 5);  //v.insert(position, number of times to insert,
		//value this insert 5, 10 times at the begin of vector.


	//copy a vector
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v1(v1.begin(), v1.end(), v2.begin()); // (start address of copy, end address of copy
											//starting address of where to copy)

	//methord-2
	vector<int> v5;
	int arr[] = {1,2,3,4,5}
	v5.assign(arr, arr+n);

	//methord -3
	vector<int> v6;
	v6.assign(10,0); //assign 10, 0s to vector v6. (size, value)

	//delete a value from vector.
	v.erase(it); //it = iterator to that delete position.

	//remove all values.
	v.clear();
	v = {};  //both methord works

	//resize an vector.
	vector<int> v = {1,2,3,4,4,4};
	v.resize(4); //now it only contain 4 items from start rest all delets.
	v.resize(10);// {1,2,3,4,4,4,0,0,0,0}

	//how many items are in between 2 iterator.
	auto it = v.begin();
	auto it2 = v.end();
	cout << distance(it, it2); // print number of items at vector v.

	return 0;
}

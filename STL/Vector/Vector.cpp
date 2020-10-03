#include <iostream>
#include <vector>
using namespace std;

template<typename T>
ostream& operator<<(ostream& vout, const vector<T>& vec) {
	for (T item : vec) {
		vout << item << " ";
	}
	return vout;
}

template<typename u, typename v>
ostream& operator<<(ostream& vout, const vector<pair<u, v>>& vec) {
	for (pair<u, v> item : vec) {
		vout << item.first << " " << item.second;
	}
	return vout;
}

int main() {
	// A empty vector
	vector<int> empty_vec;  // {}

	empty_vec.push_back(1); // {1} creates a copy 
	cout << empty_vec << endl;

	empty_vec.emplace_back(2); // {1, 2} constructs the object using the args given
	cout << empty_vec << endl;

	
	vector<pair<int, int>> pair_vec;

	pair_vec.push_back({ 3, 4 }); // {3, 4} creates a copy 
	cout << pair_vec << endl;

	pair_vec.emplace_back(5, 6); // (5, 6) constructs the object using the args given
	cout << pair_vec << endl;

	// Vector of size 5 with
	// everyone as 100
	vector<int> init_vec(5, 100); // {100, 100, 100, 100, 100}
	cout << init_vec << endl;

	// A vector of size 5
	// initialized with 0
	// might take garbage value,
	// dependent on the vector
	vector<int> zero_vec(5); // {0, 0, 0, 0, 0}
	cout << zero_vec << endl;

	vector<int> vec_20(5, 20); // {20, 20, 20, 20, 20}
	cout << vec_20 << endl;

	vector<int> vec_20_copy(vec_20); // {20, 20, 20, 20, 20} // copy constructor
	cout << vec_20_copy << endl;

	// Take the vector to be {10, 20, 30, 40}
	vector<int> v = { 10, 20, 30, 40 };
	cout << v << endl;

	vector<int>::iterator it = v.begin();

	it++;
	cout << *(it) << " " << endl; // prints 20

	it = it + 2;
	cout << *(it) << " " << endl; // prints 40
	
	vector<int>::iterator it_end = v.end();

	cout << *(--it_end) << endl;

	cout << v[0] << " " << v.at(0) << endl;

	cout << v.back() << endl; // last element
	
	// Ways to print the vector

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}
	cout << endl;

	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}
	cout << endl;

	for (auto it : v) {
		cout << it << " ";
	}
	cout << endl;

	// {10, 20, 12, 23}
	v = { 10, 20, 12, 23 };
	v.erase(v.begin() + 1);
	cout << v << endl;

	// {10, 20, 12, 23, 35}
	v = { 10, 20, 12, 23, 35 };
	v.erase(v.begin() + 2, v.begin() + 4); // // {10, 20, 35} [start, end)
	cout << v << endl;

	// Insert function

	vector<int>v_100(2, 100); // {100, 100}
	cout << v_100 << endl;

	v_100.insert(v_100.begin(), 300); // {300, 100, 100};
	cout << v_100 << endl;

	v_100.insert(v_100.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}
	cout << v_100 << endl;

	vector<int> copy(2, 50); // {50, 50}
	cout << copy << endl;

	v_100.insert(v_100.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}
	cout << v_100 << endl;

	// {10, 20}
	v_100 = { 10, 20 };
	cout << v_100.size(); // 2
	cout << v_100 << endl;

	//{10, 20}
	v_100 = { 10, 20 };
	v_100.pop_back(); // {10}
	cout << v_100 << endl;

	// v1 -> {10, 20}
	// v2 -> {30, 40}
	vector<int> v1 = { 10, 20 };
	vector<int> v2 = { 30, 40 };
	v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}

	v_100.clear(); // erases the entire vector

	cout << v_100.empty();
	
	return 0;
}

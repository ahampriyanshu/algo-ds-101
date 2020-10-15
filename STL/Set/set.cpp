#include <bits/stdc++.h>
using namespace std;
//set is a ordered pair of item, this data structure is used when you need all the
//elements to be always sorted.
int main()
{
	set <int, greater <int> > s1;

	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);
	s1.insert(50);
	s1.insert(10);

	set <int, greater <int> > :: iterator itr;
	cout << "\nThe set s1 is : ";
	for (itr = s1.begin(); itr != s1.end(); ++itr)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	set <int> s2(s1.begin(), s1.end());

	cout << "\nThe set s2 after assign from s1 is : ";
	for (itr = s2.begin(); itr != s2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	cout << "\ns2 after removal of elements less than 30 : ";
	s2.erase(s2.begin(), s2.find(30));
	for (itr = s2.begin(); itr != s2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}

	int num;
	num = s2.erase (50);
	cout << "\ns2.erase(50) : ";
	cout << num << " removed \t" ;
	for (itr = s2.begin(); itr != s2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}

	cout << endl;

	cout << "s1.lower_bound(40) : "
		<< *s1.lower_bound(40) << endl;
	cout << "s1.upper_bound(40) : "
		<< *s1.upper_bound(40) << endl;

	cout << "s2.lower_bound(40) : "
		<< *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40) : "
		<< *s2.upper_bound(40) << endl;

		// find an item in set. O(logn)
		auto it = s2.find(1)
		//if item is not found it returns end() iterator.
	return 0;
}
/*
	Set is similar to multiset, unordered set except the fact that.
	unorderedset is implemented using hash table, hence insert, delete, find is much faster
	than set.
*/

'''
Strand Sort is a sorting algorithm that works in O(n) time if list is already sorted and works in O(n*n) in worst case.
'''

#include <bits/stdc++.h> 
using namespace std; 

//Templates start here
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long
#define fo(i, j, k, in) for (int i = j; i < k; i += in)
#define refo(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j) fo(i, 0, j, 1)
#define rerep(i, j) fo(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define reall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin() l it != l.end(); it++)
#define in(A, B, C) assert(B <= A && A <= C)
#define MOD (int)1e9
#define MOD7 1000000007
#define PI 3.1415926535897932384626433832795
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef map<int, int> MPII;
typedef map<long long, long long> MPLL;
typedef set<int> SETI;
typedef multiset<int> MSETI;
//Templates end here

//I'm not using my templates for better understanding, else above templates can be easily used, you can alse benefit yourself just copy above templates and use them

void strandSort(list<int> &ip, list<int> &op) 
{ 
    if (ip.empty()) 
        return; 
    list<int> sublist; 
    sublist.push_back(ip.front()); 
    ip.pop_front(); 
    for (auto it = ip.begin(); it != ip.end(); ) 
    { 
        if (*it > sublist.back()) { 
            sublist.push_back(*it); 
            it = ip.erase(it); 
        } 
        else
            it++; 
    } 
    op.merge(sublist); 
    strandSort(ip, op); 
} 
int main(void) 
{ 
    list<int> ip{10, 5, 30, 40, 2, 4, 9}; 
    list<int> op; 
    strandSort(ip, op); 
    for (auto x : op) 
        cout << x << " "; 
    return 0; 
} 
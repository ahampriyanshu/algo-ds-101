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

int binSearch(int arr[], int, int, int);
int expoSearch(int arr[], int n, int x) 
{ 
    if (arr[0] == x) 
        return 0; 
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2; 
    return binSearch(arr, i/2, min(i, n), x); 
} 
int binSearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binSearch(arr, l, mid-1, x); 
        return binSearch(arr, mid+1, r, x); 
    } 
    return -1; 
} 
int main(void) 
{ 
    int n,x;
    cout<<"\nEnter the size of input array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array elements : ";
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    cout<<"\nEnter the number to be searched : ";
    cin>>x; 
   int result = expoSearch(arr, n, x); 
   (result == -1)? printf("\nElement is not present in array") : printf("\nElement is present at index %d", result); 
   return 0; 
} 
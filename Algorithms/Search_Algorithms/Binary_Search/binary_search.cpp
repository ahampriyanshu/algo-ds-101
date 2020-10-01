// binary search

#include <bits/stdc++.h>
using namespace std;

int main()

{
  int n, i, l, h, mid, key;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  l = 0;
  h = n - 1;

  cout << "enter the key you want to search : ";
  cin >> key;
  while (h >= l) {
    mid = (l + h) / 2;

    if (arr[mid] == key) {
      cout << "found\n";
      return 0;
    } else if (key > mid) {
      l = mid + 1;
    } else if (key < mid) {
      h = mid - 1;
    }
  }

  cout << "element not found \n" << endl;

  return 0;
}
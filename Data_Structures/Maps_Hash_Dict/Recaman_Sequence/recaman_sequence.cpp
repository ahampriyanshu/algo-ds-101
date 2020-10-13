#include <bits/stdc++.h>
using namespace std;

int get_recaman_sequence(int n)
{
  int *arr = new int[n];
  arr[0] = 0;
  cout << arr[0];

  for (int i = 1; i < n; i++)
  {
    int curr_element = arr[i - 1] - i;
    for (int j = 0; j < i; j++)
    {
      if ((arr[j] == curr_element) || curr_element < 0)
      {
        curr_element = arr[i - 1] + i;
        break;
      }
    }
    arr[i] = curr_element;
    cout << arr[i];
  }

  delete[] arr;
}
int main()
{
  int n;
  cout << "enter the number";
  cin >> n;
  cout << get_recaman_sequence(n);
  return 0;
}
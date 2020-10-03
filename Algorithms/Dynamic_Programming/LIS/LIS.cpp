#include <bits/stdc++.h>
using namespace std;

/*
Input Format: length of the array and contents of the array
Output Format: length of LIS and contents of the LIS
ALgorithm: Bottom Up Dynamic programming
Time Complexity: O(N^2), where N is the length of the array
Space Complexity: O(N^2)

Sample Input and Output

**Sample Input 1:**

Enter the number of elements of the array: 8

Enter the elements of the array: 1 8 5 9 6 2 4 7

The length of LIS is: 4

The LIS is: 1 5 6 7

**Sample Input 2:**

Enter the number of elements of the array: 10

Enter the elements of the array: 1 2 3 6 5 8 9 4 7 6

The length of LIS is: 6

The LIS is: 1 2 3 6 8 9

Graph contains cycle!
*/

int main()
{

  int n; // number of elements of the array
  cout << "\nEnter the number of elements of the array: ";
  cin >> n;

  vector<int> a(n);

  vector<int> lis(n); // for storing the longest increasing subsequence size of each index

  vector<vector<int>> seq(n); // storing the longest increasing subsequence for each index from 0 to n-1

  cout << "\nEnter the elements of the array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // initialising the LIS for each index to 1
  for (int i = 0; i < n; i++)
  {
    lis[i] = 1;
  }

  // counting the LIS in bottom up manner dynamic programming
  for (int i = 1; i < n; i++)
  {
    vector<int> tmp;
    for (int j = 0; j < i; j++)
    {
      // if the current LIS value is less that the value we just calculated we have got a new LIS for index i
      if (a[i] > a[j] and lis[i] < lis[j] + 1)
      {
        lis[i] = lis[j] + 1;
        tmp.push_back(a[j]);
      }
    }
    tmp.push_back(a[i]);
    seq[i] = tmp;
  }

  int answerIndex = 0;
  int maxLength = *max_element(lis.begin(), lis.end());
  for (int i = 0; i < n; i++)
  {
    if ((int)seq[i].size() == maxLength)
    {
      answerIndex = i;
      break;
    }
  }
  // printing the LIS and contents of the LIS
  cout << "\nThe length of LIS is: " << maxLength << '\n';
  cout << "\nThe LIS is: ";
  for (auto u : seq[answerIndex])
  {
    cout << u << " ";
  }
  cout << '\n';
}
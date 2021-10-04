->It is a simple c++ code for searching a element in matrix.
 
  ===========
 c++ program
 ============

#include <bits/stdc++.h>
using namespace std;
int search(int n, vector<vector<int>> mat, int x)
{
    if (n == 0)
        return -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

            if (mat[i][j] == x)
            {
                cout << "Row number is: " << i + 1 << endl;
                cout << "Column number is: " << j + 1 << endl;
                return 1;
            }
    }

    cout << "Element not found\n";
    return 0;
}

int main()
{
    int row, search_val;
    cout << "Enter the size of the square matrix:  ";
    cin >> row;
    cout << "Enter the element you want to search in the matrix:  ";
    cin >> search_val;
    vector<int> temp(row, 0);
    vector<vector<int>> v(row, temp);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << "Enter the mat[" << i + 1 << "][" << j + 1 << "] element: ";
            cin >> v[i][j];
        }
    }
    search(row, v, search_val);

    return 0;
}


-----------------------
        Algorithm
------------------------
 1. First two for loops are running first one is for row and second one is for the column.
 2. Check every element with x and if the element is found then print not fount.
 3.If the element is not found, then print element not founr.

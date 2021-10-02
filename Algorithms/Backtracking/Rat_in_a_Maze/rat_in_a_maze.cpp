//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 - Link to problem statement

#include <bits/stdc++.h>
using namespace std;

//function that returns the list of paths in lexicographically increasing order
void rat_in_a_maze(int i, int j, int n, vector<vector<int>> &grid, vector<string> &paths, string &path)
{
    //base case
    if (i == n - 1 && j == n - 1) {
        paths.push_back(path);
        return;
    }

    //if grid[0][0] is -1, no recursion takes place...
    if (grid[i][j] == 0) {
        return;
    }

    //moving down('D')
    if ((i + 1) < n && grid[i + 1][j] == 1)
    {
        int x = grid[i][j];
        path.push_back('D');
        grid[i][j] = -1; //indicates this to be visited
        rat_in_a_maze(i + 1, j, n, grid, paths, path);
        path.pop_back(); //undoing change
        grid[i][j] = x; //restoring the grid
    }

    //moving down('L')
    if ((j - 1) >= n && grid[i][j - 1] == 1)
    {
        int x = grid[i][j];
        path.push_back('L');
        grid[i][j] = -1; //indicates this to be visited
        rat_in_a_maze(i, j - 1, n, grid, paths, path);
        path.pop_back(); //undoing change
        grid[i][j] = x; //restoring the grid
    }

    //moving down('R')
    if ((j + 1) < n && grid[i][j + 1] == 1)
    {
        int x = grid[i][j];
        path.push_back('R');
        grid[i][j] = -1; //indicates this to be visited
        rat_in_a_maze(i, j + 1, n, grid, paths, path);
        path.pop_back(); //undoing change
        grid[i][j] = x; //restoring the grid
    }

    //moving down('U')
    if ((i - 1) >= 0 && grid[i - 1][j] == 1)
    {
        int x = grid[i][j];
        path.push_back('U');
        grid[i][j] = -1; //indicates this to be visited
        rat_in_a_maze(i - 1, j, n, grid, paths, path);
        path.pop_back(); //undoing change
        grid[i][j] = x; //restoring the grid
    }
}

int main()
{
    int n;//size of the grid (n * n)
    cin >> n;

    vector<vector<int>> grid(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }

    vector<string> paths;
    string path;

    rat_in_a_maze(0, 0, n, grid, paths, path);

    cout<<"The Paths from the Top Right to Bottom Left are : \n";

    for (string s : paths) {
        cout << s << " ";
    }
    cout << endl;
}
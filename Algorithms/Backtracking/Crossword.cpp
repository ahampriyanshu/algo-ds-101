/*
  Problem description:
  A 10 x 10 Crossword grid is provided,along with 
  a set of words (or names of places) which need 
  to be filled into the grid.The cells in the grid 
  are initially,either + signs or – signs.
  Cells marked with a ‘+’ have to be left as they are.
  Cells marked with a ‘-‘ need to be filled up with an 
  appropriate character.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 10

//Return index of word which is not filled in crossword
bool findString(vector<bool> &visited, int &index)
{
  int n = visited.size();
  for (int i = 0; i < n; i++)
    if (visited[i] == 0)
    {
      index = i;
      return false;
    }
  return true;
}

//check if word can be filled in a column
bool isPossible_col(vector<vector<char>> &grid, int row, int col, string word)
{
  int len = word.size();
  for (int i = 0; i < len; i++)
  {
    if ((col + i) >= 10)
      return false;
    if (grid[row][col + i] != '-' && grid[row][col + i] != word[i])
      return false;
  }
  return true;
}

//check if word can be filled in a row.
bool isPossible_row(vector<vector<char>> &grid, int row, int col, string word)
{
  int len = word.size();
  for (int i = 0; i < len; i++)
  {
    if ((row + i) >= 10)
      return false;
    if (grid[row + i][col] != '-' && grid[row + i][col] != word[i])
      return false;
  }
  return true;
}

// Fill all words in crossword & return true if all words can be filled in the grid.
bool crossword(vector<vector<char>> &grid, vector<bool> &visited, vector<string> &words)
{
  int index;
  if (findString(visited, index))
    return true;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (grid[i][j] == '-' || grid[i][j] == words[index][0])
      {
        if (isPossible_col(grid, i, j, words[index]))
        {
          string prev_state = "";
          for (int k = 0; k < words[index].size(); k++)
            prev_state += grid[i][j + k], grid[i][j + k] = words[index][k];
          visited[index] = 1;
          bool flag = crossword(grid, visited, words);
          if (flag)
            return true;
          visited[index] = 0;
          for (int k = 0; k < words[index].size(); k++)
            grid[i][j + k] = prev_state[k];
        }
        if (isPossible_row(grid, i, j, words[index]))
        {
          string prev_state = "";
          for (int k = 0; k < words[index].size(); k++)
            prev_state += grid[i + k][j], grid[i + k][j] = words[index][k];
          visited[index] = 1;
          bool flag = crossword(grid, visited, words);
          if (flag)
            return true;
          visited[index] = 0;
          for (int k = 0; k < words[index].size(); k++)
            grid[i + k][j] = prev_state[k];
        }
      }
    }
  }
  return false;
}
int main()
{ //1. given crossword grid
  vector<vector<char>> grid(N, vector<char>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> grid[i][j];
  
  //2. given words to be filled in Crossword
  int num_of_words;
  vector<string> words;
  string word;
  cin>>num_of_words;
  for(int i=0;i<num_of_words;i++)
  {
  	cin>>word;
  	words.push_back(word);
  }

  //3. calling function crossword to fill the grid
  vector<bool> visited(num_of_words, 0);
  if (crossword(grid, visited, words))
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        cout << grid[i][j];
      cout << endl;
    }
  }
  else
  {
    cout << "We Cannot fill all the words in the grid" << endl;
  }
}
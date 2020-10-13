#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    //basically what we need to do is that we need to create a map that will store the characters of a particular string
    // Now compare it with every other string
    //O(n3) solution
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;

    for (int i = 0; i < strs.size(); i++)
    {
        string eq = strs[i];
        sort(eq.begin(), eq.end());
        m[eq].push_back(strs[i]);
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        res.push_back(it->second);
    }
    return res;
}

int main()
{
    int n;
    cout << "Input number of words in string: ";
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter word: ";
        cin >> strs[i];
    }
    vector<vector<string>> res = groupAnagrams(strs);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}
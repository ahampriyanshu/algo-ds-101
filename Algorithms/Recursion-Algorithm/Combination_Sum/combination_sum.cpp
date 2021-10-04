#include <bits/stdc++.h>

using namespace std;

void generatePermutation(vector<int> &arr, int target, int currSum, int currIndex, vector<vector<int>> &ans,
                         vector<int> &currCandidates) {
    if (currSum == target) {
        ans.push_back(currCandidates);
        return;
    }
    if (currSum > target) return;
    for (int i = currIndex; i < arr.size(); i++) {
        currCandidates.push_back(arr[i]);
        currSum += arr[i];
        generatePermutation(arr, target, currSum, i, ans, currCandidates);
        currCandidates.pop_back();
        currSum -= arr[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    generatePermutation(candidates, target, 0, 0, ans, temp);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, target;
    cin >> n >> target;
    vector<int> candidates(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    vector<vector<int>> solution = combinationSum(candidates, target);
    for (auto &i : solution) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
//Input
4 7
2 3 6 7
//Output
2 2 3
7

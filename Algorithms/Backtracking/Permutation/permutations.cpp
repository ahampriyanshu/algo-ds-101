#include<iostream>
using namespace std;
void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>> &res, int i){
   if(curr.size()==nums.size())
        //one possible permutation obtained-
        res.push_back(curr);
   else {
        //backtracking algorithm implementation-
        for(int j=i; j<nums.size(); j++){
           curr.push_back(nums[j]);
           swap(nums[j], nums[i]);
           solve(nums, curr, res, i+1);
           swap(nums[j], nums[i]);
           curr.pop_back();
        }
   }
   return;
}
vector<vector<int>> permute(vector<int>& nums) {
   vector<vector<int>>res;
   vector<int>curr;
   solve(nums, curr, res, 0);
   return res;
}
int main() {
   int n;
   cin >> n;
   vector<int>arr(n);
   for(int i=0; i<n; i++)
       cin >> arr[i];
   vector<vector<int>> answer = permute(arr);
   //printing all the possible permutation arrays -
   for(int i=0; i<answer.size(); i++){
       cout << "[ " ;
       for(int j=0; j<n; j++){
           cout << answer[i][j] << " " ;
       }
       cout << "]" << "\n";
   }
   return 0;
}

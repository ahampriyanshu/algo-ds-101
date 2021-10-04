#include<bits/stdc++.h>
using namespace std;

/*Naive Approach: Check for all pairs if they adds up to the target or not
TC: O(n*n) SC: O(1)
*/
pair<int, int> findTwoSumNaive(vector<int> nums, int target){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] + nums[j] == target)
                return {nums[i], nums[j]};
        }
    }
    return {-1, -1};
}
/*Better Approach: Sort the given array
->create two pointers one of which points to the first element and another one to the last element.
->check if both the values pointed to by these pointers adds up to the target or not.
->if yes, return the result.
->otherwise, if the sum is lesser than the target increment left pointer
->           otherwise decrement the right pointer.
->The above intuition works because the array is sorted.
TC: O(nlogn) SC: O(n)
*/
pair<int, int> findTwoSumBetter(vector<int> nums, int target){
    sort(nums.begin(), nums.end());
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo < hi){
        if(nums[lo] + nums[hi] == target)
            return {nums[lo],nums[hi]};
        nums[lo] + nums[hi] < target ? lo++ : hi--;
    }
    return {-1, -1};
}

/*Optimal Approach: 
->Use a hashmap to store the numbers as you traverse.
->At any point if you had added a value equal to the target - current_number in the hashmap.
->Then we have our ans as {current_number, target - current_number} which adds up to the target value.
->otherwise return {-1, -1} as the result.
TC: O(n) SC: O(n)
considering the hashmap works in O(1) on an average.
*/
pair<int, int> findTwoSumOptimal(vector<int> nums, int target){
    unordered_map<int, int>mp;
    for(auto &a : nums){
        if(mp[target - a])
            return {target - a, a};
        mp[a]++;
    }
    return {-1, -1};
}
int main(){
    
    //get the input array as a line of string
    string s;
    getline(cin, s);
    
    //get the target value 
    int target;
    cin >> target;
    
    stringstream ss(s);
    
    vector<int> nums;
    int value;
    
    //string values to integer values and add it the nums array
    while(ss >> value)nums.push_back(value);
    
    //a pair of values to store the result
    pair<int, int> values = findTwoSumOptimal(nums, target);
    
    //if both the values of the result are -1
    //it means no such pair exists that adds up to the target value
    //otherwise, print a valid pair of values
    if(values.first == -1 and values.second == -1){
        cout << "No such pair exists" << endl;
    } else{
        cout << values.first <<" and " << values.second
            <<" adds up to " << target << endl;
    }
      
    
}
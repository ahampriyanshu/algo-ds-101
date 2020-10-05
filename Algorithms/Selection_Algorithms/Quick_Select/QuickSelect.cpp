/**
* Finding Kth largest element in an array using QuickSelect algorithm
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       return findKthLargest(nums, 0, nums.size()-1, nums.size()-k);
    }

    int findKthLargest(vector<int>& nums, int left, int right ,int k) {
        int pivot = nums[right];
        int leftMark = left;
        for (int i = left; i<right; i++) {
            if(nums[i] <= pivot)
                swap(nums, leftMark++, i);
        }
        swap(nums, leftMark, right);

    if (leftMark == k)// Found kth smallest number
		return nums[leftMark];
	else if (leftMark < k)// Check right part
		return findKthLargest(nums, leftMark + 1, right, k);
	else // Check left part
		return findKthLargest(nums, left, leftMark - 1, k);
}

void swap( vector<int>& A, int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}
};
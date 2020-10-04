# Given an unsorted array of integers, find the length of longest increasing subsequence.

# Example:

# Input: [10,9,2,5,3,7,101,18]
# Output: 4
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
# Note:

# There may be more than one LIS combination, it is only necessary for you to return the length.
# Your algorithm should run in O(n2) complexity.
# Follow up: Could you improve it to O(n log n) time complexity?


def lengthoflis(nums):
    # it is storing the minmum number ending with subsequece size of i+1
    tails = [0] * len(nums)
    size = 0
    for x in nums:
        l, r = 0, size
        while l < r:
            mid = (r+l)//2
            if x > tails[mid]:
                l = mid+1
            else:
                r = mid
        tails[l] = x
        size = max(size, l+1)
    return size

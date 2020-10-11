import heapq
 
class Solution:
    def findKthLargest(self, nums: 'List[int]', k: 'int') -> 'int':
 
        # Time complexity : O(N*logK)
        # Space complexity : O(K)
 
        heap = []
        
        for i in nums :
            heapq.heappush(heap, i)
            
            if len(heap) > k :
                heapq.heappop(heap)
        
        return heapq.heappop(heap)
 
        
    def findKthLargest(self, nums: 'List[int]', k: 'int') -> 'int':
 
        # Time complexity : O(N)
        # Space complexity : O(1)
        
        def partition(l, r, i):
            
            start = l
            pivot = nums[i]
            nums[i], nums[start] = nums[start], nums[i]
            
            l += 1
            
            while l <= r :
                
                while l<=r and nums[l] <= pivot :
                    l += 1
                while l<=r and nums[r] > pivot :
                    r -= 1
                    
                if l < r :
                    nums[l], nums[r] = nums[r], nums[l]
                    l += 1
                    r -= 1
            
            nums[r], nums[start] = nums[start], nums[r]
            return r
        
        def select(l, r, k_smallest):
            
            if l == r :
                return nums[l]
            
            i = random.randint(l, r)
            i = partition(l, r, i)
            
            if k_smallest == i :
                return nums[i]
            elif k_smallest > i :
                return select(i+1, r, k_smallest)
            else :
                return select(l, i-1, k_smallest)
        
        return select(0, len(nums)-1, len(nums)-k)

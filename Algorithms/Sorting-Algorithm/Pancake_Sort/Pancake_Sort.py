input_vector = [3,6,8,3,1,4,8,9,5,3,2,5,8,9,1]

def pancake_sort(nums):
    arr_len = len(nums)
    while arr_len > 1:
        mi = nums.index(max(nums[0:arr_len]))
        nums = nums[mi::-1] + nums[mi+1:len(nums)]
        nums = nums[arr_len-1::-1] + nums[arr_len:len(nums)]
        arr_len -= 1
    return nums

print(pancake_sort(input_vector))
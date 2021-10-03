def mergeSort(arr, n):
    # A temp_arr is created to store
    # sorted array in merge function
    temp_arr = [0]*n
    return _merge_sort(arr, temp_arr, 0, n-1)
 
# This Function will use MergeSort to count inversions
 
def _merge_sort(arr, temp_arr, left, right):
 
    # A variable inversion_count is used to store
    # inversion counts in each recursive call
 
    inversion_count = 0
 
    # We will make a recursive call if and only if
    # we have more than one elements
 
    if left < right:
 
        # middle is calculated to divide the array into two subarrays
        # Floor division is must in case of python
 
        middle = (left + right)//2
 
        # It will calculate inversion
        # counts in the left subarray
 
        inversion_count += _merge_sort(arr, temp_arr,
                                    left, middle)
 
        # It will calculate inversion
        # counts in right subarray
 
        inversion_count += _merge_sort(arr, temp_arr,
                                  middle + 1, right)
 
        # It will merge two subarrays in
        # a sorted subarray
 
        inversion_count += merge(arr, temp_arr, left, middle, right)
    return inversion_count
 
# This function will merge two subarrays
# in a single sorted subarray
def merge(arr, temp_arr, left, middle, right):
    i = left     # Starting index of left subarray
    j = middle + 1 # Starting index of right subarray
    k = left     # Starting index of to be sorted subarray
    inversion_count = 0
 
    # Conditions are checked to make sure that
    # i and j don't exceed their
    # subarray limits.
 
    while i <= middle and j <= right:
 
        # There will be no inversion if arr[i] <= arr[j]
 
        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            k += 1
            i += 1
        else:
            # Inversion will occur.
            temp_arr[k] = arr[j]
            inversion_count += (middle-i + 1)
            k += 1
            j += 1
 
    # Copy the remaining elements of left
    # subarray into temporary array
    while i <= middle:
        temp_arr[k] = arr[i]
        k += 1
        i += 1
 
    # Copy the remaining elements of right
    # subarray into temporary array
    while j <= right:
        temp_arr[k] = arr[j]
        k += 1
        j += 1
 
    # Copy the sorted subarray into Original array
    for loop_var in range(left, right + 1):
        arr[loop_var] = temp_arr[loop_var]
         
    return inversion_count

#Code start
arr = [1, 20, 6, 4, 5]
n = len(arr)
result = mergeSort(arr, n)
print("Number of inversions are", result)
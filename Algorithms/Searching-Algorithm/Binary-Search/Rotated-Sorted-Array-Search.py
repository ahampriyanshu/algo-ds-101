 def pivotedBinarySearch(arr, n, key):

    pivot = findPivot(arr, 0, n-1);

    # If we didn't find a pivot,
    # then array is not rotated at all
    if pivot == -1:
        return binarySearch(arr, 0, n-1, key);

    # If we found a pivot, then first
    # compare with pivot and then
    # search in two subarrays around pivot
    if arr[pivot] == key:
        return pivot
    if arr[0] <= key:
        return binarySearch(arr, 0, pivot-1, key);
    return binarySearch(arr, pivot + 1, n-1, key);


# Function to get pivot. For array
# 3, 4, 5, 6, 1, 2 it returns 3
# (index of 6)
def findPivot(arr, low, high):

    # base cases
    if high < low:
        return -1
    if high == low:
        return low

    # low + (high - low)/2;
    mid = int((low + high)/2)

    if mid < high and arr[mid] > arr[mid + 1]:
        return mid
    if mid > low and arr[mid] < arr[mid - 1]:
        return (mid-1)
    if arr[low] >= arr[mid]:
        return findPivot(arr, low, mid-1)
    return findPivot(arr, mid + 1, high)

def binarySearch(arr, low, high, key):

    if high < low:
        return -1

    # low + (high - low)/2;
    mid = int((low + high)/2)

    if key == arr[mid]:
        return mid
    if key > arr[mid]:
        return binarySearch(arr, (mid + 1), high,
                                            key);
    return binarySearch(arr, low, (mid -1), key);

arr1 = []
print("Please Enter number of elements in array")
n = int(input())
for i in range(n):
    demo = int(input())
    arr1.append(demo)

print("Please enter the element in array")
key = int(input())

if key not in arr1:
    print("Element not in array")

print("Index of the element is : ",
      pivotedBinarySearch(arr1, n, key))

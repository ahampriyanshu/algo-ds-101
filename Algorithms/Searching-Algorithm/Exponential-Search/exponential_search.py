def bin_search(arr, x, low=0, high=None):
    if high is None:
        high = len(arr) - 1
    if high < low:
        return -1
    mid = (high + low) // 2
    if arr[mid] == x:
        return mid
    elif arr[mid] < x:
        return bin_search(arr, x, mid+1, high)
    elif arr[mid] > x:
        return bin_search(arr, x, low, mid)
    return -1


def exp_search(arr, x):
    i = 1
    while True:
        if 2**i >= len(arr):
            return bin_search(arr, x, 2**(i-1)-1)
        elif arr[2**i] == x:
            return 2**i
        elif arr[2**i] > x:
            return bin_search(arr, x, 2**(i-1), 2**i - 1)
        i += 1


    
user_input = input("Enter numbers separated by comma:\n").strip()
sequence = [int(item.strip()) for item in user_input.split(",")]
target = int(input("Enter a single number to be found in the list:\n").strip())
result = exp_search(sequence, target)
if result == -1:
    print(f"{target} was not found in list.")
else:
    print(f"{target} was found in position {result} of list.")
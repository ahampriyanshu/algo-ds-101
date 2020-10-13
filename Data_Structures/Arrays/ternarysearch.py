def ternarySearch(l, r, key, arr):
    if(r >= l):

        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3
        print(mid1)
        print(mid2)
        print(r)
        # Check if key is present at any mid
        if (ar[mid1] == key):
            return mid1

        if (arr[mid2] == key):
            return mid2
        if(arr[mid1] == key):
            return mid1
        elif(arr[mid2] == key):
            return mid2
        elif(key < arr[mid1]):
            return ternarySearch(l, mid1-1, key, arr)
        elif(key > arr[mid2]):
            return ternarySearch(mid2+1, r, key, arr)
        else:
            return ternarySearch(mid1+1, mid2-1, key, arr)

    return -1


# Driver code
l, r, p = 0, 9, 5

# Get the array
# Sort the array if not sorted
ar = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Starting index
l = 0

# length of array
r = 9

# Checking for 5

# Key to be searched in the array
key = 5

# Search the key using ternarySearch
p = ternarySearch(l, r, key, ar)

# Print the result
print("Index of", key, "is", p)

# Checking for 50

# Key to be searched in the array
key = 50
l = 0
r = 9
# Search the key using ternarySearch
p = ternarySearch(l, r, key, ar)

# Print the result
print("Index of", key, "is", p)

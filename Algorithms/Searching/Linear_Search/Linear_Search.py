# The below given code implements Linear Search algorithm.
# The program prints the index number of the element if the searched element is present in the list, else it prints -1.

def LinearSearch(arr, element):
    for i in range (len(arr)):
        if arr[i] == element:
            return i
    return -1

A = list(map(int, input("Enter the elements of list: ").split()))
searchKey = int(input("Enter element to be searched: "))
print(LinearSearch(A, searchKey))
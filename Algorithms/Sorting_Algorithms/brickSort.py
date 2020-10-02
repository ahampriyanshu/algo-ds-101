def brickSort(array, n):
    isSorted = 0
    while isSorted == 0:
        isSorted = 1
        temp = 0
        for i in range(1, n - 1, 2):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                isSorted = 0

        for i in range(0, n - 1, 2):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                isSorted = 0
    return


arr = [23,45,67,89]
n = len(arr)

brickSort(arr, n);
for i in range(0, n):
    print(arr[i], end=' ')

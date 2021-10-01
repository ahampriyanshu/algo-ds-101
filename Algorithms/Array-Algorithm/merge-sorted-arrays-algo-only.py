# O(nk) time | O(n+k) space - where n is the total number of array elements and k is the nunber of arrays

def mergeSortedArrays(arrays):
    sortedList = []
    elementIdxs = [0 for array in arrays]
    while True:
        smallestItems = []
        for arrayIdx in range(len(arrays)):
            relevantArray = arrays[arrayIdx]
            elementIdx = elementIdxs[arrayIdx]
            if elementIdx == len(relevantArray):
                continue
            smallestItems.append(
                {"arrayIdx": arrayIdx, "num": relevantArray[elementIdx]})
        if len(smallestItems) == 0:
            break
        nextItem = getMinValue(smallestItems)
        sortedList.append(nextItem["num"])
        elementIdxs[nextItem["arrayIdx"]] += 1
    return sortedList


def getMinValue(items):
    minValueIdx = 0
    for i in range(1, len(items)):
        if items[i]["num"] < items[minValueIdx]["num"]:
            minValueIdx = i
    return items[minValueIdx]

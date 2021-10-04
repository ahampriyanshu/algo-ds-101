# BINARY INSERTION SORTING

Binary search is used to reduce the number of comparisons in Insertion sort. This modification is known as Binary Insertion Sort.

Binary Insertion Sort use binary search to find the proper location to insert the selected item at each iteration. In insertion sort, it takes O(i) at ith iteration in worst case. Using binary search, it is reduced to O(log i).

**For Example:**

If we know insertion sort and binary search already, then its pretty straight forward. When we insert a piece in insertion sort, we must compare to all previous pieces.Like if we want to move this [2] to the correct place, we would have to compare to 7 pieces before we find the right place.
[1][3][3][3][4][4][5] ->[2]<- [11][0][50][47]

However, if we start the comparison at the half way point (like a binary search), then we will only compare to 4 pieces! This can be done because we know the left pieces are already in order.

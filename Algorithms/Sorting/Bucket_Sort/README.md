## BUCKET SORT

Bucket sort is mainly useful when input is uniformly distributed over a range. In the Bucket Sorting technique, the data items are distributed in a set of buckets. Each bucket can hold a similar type of data. After distributing, each bucket is sorted using another sorting algorithm. After that, all elements are gathered on the main list to get the sorted form.

The complexity of the Bucket Sort Technique :
1. Time Complexity: O(n + k) for best case and average case and O(n^2) for the worst case.
2. Space Complexity: O(nk) for worst case

**FOR EXAMPLE:**
Input:
A list of unsorted data: 0.25 0.36 0.58 0.41 0.29 0.22 0.45 0.79 0.01 0.69
Array before Sorting: 0.25 0.36 0.58 0.41 0.29 0.22 0.45 0.79 0.01 0.69

Output:
Array after Sorting: 0.01 0.22 0.25 0.29 0.36 0.41 0.45 0.58 0.69 0.79

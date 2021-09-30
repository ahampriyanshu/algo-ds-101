##Tim Sorting Algorithm

TimSort algorithm is a sorting technique widely used in programming. Java and python use this algorithm in their built-in sort() methods. It is a combined hybrid of two other sorting techniques – Insertion-Sort and Merge-Sort

While TimSort is a complex algorithm in itself, where it looks for an ideal minimum size called “minrun”, performs “galloping” in merge-sort to avoid iterations for pre-sorted elements, etc., this post deals with a simple and basic implementation.

It is, however, noteworthy that merge sort is most efficient when the size of the array is a power of 2. Take for instance an array of size 16, which is 2^4. Hence, in each recursion or iteration (depends on the implementation of merge-sort), the array splits into 2 equal subarrays. This happens until we are left with 16 single elements. These are then reconstructed to get the sorted array.

Also, note that insertion sort works best when the size of the array is less. Hence in TimSort, minrun is usually set between 32 and 64. In this implementation, since we are not finding minrun, we are taking 32 as minrun. And from the previous point, we understand that the algorithm is more efficient when (size_of_arr/32) is a power of 2.

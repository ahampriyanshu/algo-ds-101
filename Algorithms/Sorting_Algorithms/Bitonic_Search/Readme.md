# Bitonic Sort

Bitonic Sort is a classic parallel algorithm for sorting which sorts in O(n Log 2n) comparisons. It must be used if number of elements to sort are 2^n. The procedure of bitonic sequence fails if the number of elements are not in aforementioned quantity precisely.

A sequence is called Bitonic if it is first increasing, then decreasing. In other words, an array arr[0..n-i] is Bitonic if there exists an index i where 0<=i<=n-1 such that 
**x0 <= x1 …..<= xi  and  xi >= xi+1….. >= xn-1**
1. A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
2. A rotation of Bitonic Sequence is also bitonic.

**EXAMPLE:**

Converting 3, 7, 4, 8, 6, 2, 1, 5 into Bitonic sequence,

1. Consider each 2-consecutive elements as bitonic sequence and apply bitonic sort on each 2- pair elements. In next step, take two 4 element bitonic sequences and so on.
2. Two 4 element bitonic sequences : A(3,7,8,4) and B(2,6,5,1) with comparator length as 2.
3. After this step, we’ll get Bitonic sequence of length 8.

OUTPUT: 1, 2, 3, 4, 5, 6, 7, 8.

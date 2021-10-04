## Circle Sort

Circle sort algorithm can be visualized by drawing concentric circles on an array of integers. The elements of the array lying on the same circle diametrically opposite to each other are compared and if found in the wrong order they are swapped. This goes on in a recursive fashion in which the array is divided into sub-arrays on which the above process is repeated until we get pairs of sorted elements which when put together form a sorted array.

**In short below two steps are repeated while there are swap operations involved in the steps.**

1. Compare the first element to the last element, then the second element to the second last element, etc.
2. Then split the array in two and recurse until there is only one single element in the array.

**For Example**

A = {6,5,3,1,8,7,2,4}

1st element is swipped with last similarly 2nd element with second last and the divides the arrays into 2 parts :

X = {4,2,3,1}      and       Y = {8,7,5,6}

Again swipping of elements takes place in similar circular manner and divides the arrays in futher 2-2 parts :

P = {1,2}  Q = {3,4}   R = {6,5}   S = {7,8}

After swipping {6,5} Final output is :

A = {1,2,3,4,5,6,7,8}

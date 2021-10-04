# BRICK SORT

Brick Sorting is basically variation of Bubble Sorting. It is divided into two phases Odd and Even Phase.
In the odd phase,bubble sort is performed on odd indexed elements and in the even phase,bubble sort is performed on even indexed elements.

**Example:**

Let's take Unsorted Array A={3, 2, 3, 8, 5, 6, 4, 1}.
Sorting will perfromed in 8 steps:

1. Pairing in even number - [3 2],[3 8],[5 6],[4 1].
2. Now in odd number - [2],[3 3],[8 5],[6 1],[4].
3. Similarly following step 1 and 2 - [2 3],[3 5],[8 1],[6 4].
4. [2],[3 3],[5 1],[8 4],[6].
5. [2 3],[3 1],[5 4],[8 6].
6. [2],[3 1],[3 4],[5 6],[8].
7. [2 1],[3 3],[4 5],[6 8].
8. [1],[2 3],[3 4],[5 6],8.

OUTPUT: [1 2],[3 3],[4 5],[6 8] - {1, 2, 3, 3, 4, 5, 6, 8}.


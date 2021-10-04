"""
Disjoint Set Union (Union Find) - DSU

DSU is a data structure which is initialized of N sets with 1 element in each, and supports the following operations:

union_sets(a, b) - unite two sets (the set where element a is located, and the set where element b is located)
find_set(v)- return the head (leader) element of the set by one of it's elements

DSU is usually implemented as a tree, where to find head element of a set we go up till the root.
Usually two optimisations are implemented:

1. path shortening
let's say you have a long chain of elements, you can cache the find_set calls and connect the deepest elements to higher elements in the tree to reduce traversion time
2. ranking system (either via size of a set, or it's depth)

Example test:
10 10
2 1
DSU1: 1
DSU2: 1
2 2
DSU1: 2
DSU2: 2
1 1 2
2 1
DSU1: 1
DSU2: 1
2 2
DSU1: 1
DSU2: 1
2 8
DSU1: 8
DSU2: 8
1 8 2
2 8
DSU1: 1
DSU2: 1
2 2
DSU1: 1
DSU2: 1
2 5
DSU1: 5
DSU2: 5

You can see that, when uniting set with element 8 and element 2, the smaller set (with 8) is united with the bigger set (with 2)
"""

from abc import abstractmethod


class AbstractDSU:
    """DSU

    Time complexity: worst case O(log n), often almost O(1)
    Space complexity: O(2n)

    Elements are numbered from 1 to n

    Args:
        n (int): number of elements (number of sets)

    """

    DEFAULT_RANK: int

    def __init__(self, n):
        self.prev = [i for i in range(n + 1)]
        self.rank = [self.DEFAULT_RANK for i in range(n + 1)]

    def _process_set_boundaries(self, x):
        """Checks that element passed is within the required range

        Args:
            x (int): element to check

        Returns:
            bool: Whether the element is within required range
        """
        # len(X) is O(1)
        if x < 1 or x > len(self.prev):
            return False
        return True

    def find_set(self, v):
        """Finds the head element of the set that contains the element passed

        Args:
            v (int): element of the set

        Returns:
            int: Head element of that set
        """
        if not self._process_set_boundaries(v):
            return -1
        if v == self.prev[v]:  # if v is root, we found the head element
            return v
        # re-connect the element higher up in the tree to not traverse the long path again
        self.prev[v] = self.find_set(self.prev[v])
        return self.prev[v]

    def union_sets(self, a, b):
        """Unite two sets that contain the elements passed

        Args:
            a (int): element of the first set
            b (int): element of the second set
        """
        if not self._process_set_boundaries(a) or not self._process_set_boundaries(b):
            return
        # Find head elements of each set, if they are equal-there is no need to unite the same set
        x = self.find_set(a)
        y = self.find_set(b)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            x, y = y, x
        # union set y into bigger set x
        # the head element of set y gets connected to head element of set x
        self.prev[y] = x
        self.update_ranks(x, y)

    @abstractmethod
    def update_ranks(self, x, y):
        """Updates the rank of the set that contains the element passed

        Assumes that set x is the bigger set

        Args:
            x (int): element of the first set
            y (int): element of the second set
        """
        raise NotImplementedError()


class DSUBySize(AbstractDSU):
    DEFAULT_RANK = 1

    def update_ranks(self, x, y):
        self.rank[x] += self.rank[y]


class DSUByRank(AbstractDSU):
    DEFAULT_RANK = 0

    def update_ranks(self, x, y):
        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1


if __name__ == "__main__":
    # Sample program to test it
    # Reads n - number of elements, q - number of queries
    # Then q lines follow with first number being the query type (t)
    # If t=1, then the query is to union sets by their elements x and y
    # If t=2, then the query is to find the set of element x
    # Output -1 if element doesn't belong to any set
    n, q = map(int, input().split())
    dsu1 = DSUBySize(n)
    dsu2 = DSUByRank(n)
    for _ in range(q):
        t, *args = map(int, input().split())
        if t == 1:
            dsu1.union_sets(*args)
            dsu2.union_sets(*args)
        elif t == 2:
            # The outputs should match, as the only difference is ranking strategy which only affects the asymptotic time complexity
            print(f"DSU1: {dsu1.find_set(args[0])}")
            print(f"DSU2: {dsu2.find_set(args[0])}")

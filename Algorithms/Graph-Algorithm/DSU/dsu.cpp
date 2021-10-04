/*
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
*/
#include <bits/stdc++.h>
using namespace std;

class AbstractDSU
{
    /*
    Time complexity: worst case O(log n), often almost O(1)
    Space complexity: O(2n)

    Elements are numbered from 1 to n

    @param n number of elements (number of sets)
    */
protected:
    vector<int> prev, rank;
    int DEFAULT_RANK = 1;

    /*
    Checks that element passed is within the required range

    @param x element to check
    @return Whether the element is within required range
    */
    bool process_set_boundaries(int x)
    {
        if (x < 1 or x > prev.size())
            return false;
        return true;
    }

public:
    AbstractDSU(int n) : prev(n + 1), rank(n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            prev[i] = i;
            rank[i] = DEFAULT_RANK;
        }
    }
    /*
    Finds the head element of the set that contains the element passed

    @param v element of the set
    @return Head element of that set
    */
    int find_set(int v)
    {
        if (!process_set_boundaries(v))
            return -1;
        if (v == prev[v]) // if v is root, we found the head element
            return v;
        // re-connect the element higher up in the tree to not traverse the long path again
        return prev[v] = find_set(prev[v]);
    }
    /*
    Unite two sets that contain the elements passed

    @param a element of the first set
    @param b element of the second set
    */
    void union_sets(int a, int b)
    {
        if (!process_set_boundaries(a) || !process_set_boundaries(b))
            return;
        // Find head elements of each set, if they are equal-there is no need to unite the same set
        int x = find_set(a), y = find_set(b);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        // union set y into bigger set x
        // the head element of set y gets connected to head element of set x
        prev[y] = x;
        update_rank(x, y);
    }
    /*
    Updates the rank of the set that contains the element passed

    Assumes that set x is the bigger set

    @param x element of the first set
    @param y element of the second set
    */
    virtual void update_rank(int x, int y) = 0;
};

class DSUBySize : public AbstractDSU
{
    int DEFAULT_RANK = 1;

public:
    DSUBySize(int n) : AbstractDSU(n) {}
    void update_rank(int x, int y)
    {
        rank[x] += rank[y];
    }
};

class DSUByRank : public AbstractDSU
{
    int DEFAULT_RANK = 0;

public:
    DSUByRank(int n) : AbstractDSU(n) {}
    void update_rank(int x, int y)
    {
        if (rank[x] == rank[y])
        {
            rank[x] += 1;
        }
    }
};

int main()
{
    /*
    Sample program to test it
    Reads n - number of elements, q - number of queries
    Then q lines follow with first number being the query type (t)
    If t=1, then the query is to union sets by their elements x and y
    If t=2, then the query is to find the set of element x
    Output -1 if element doesn't belong to any set
    */
    int n, q;
    cin >> n >> q;
    DSUBySize dsu1(n);
    DSUByRank dsu2(n);
    for (int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b;
            dsu1.union_sets(a, b);
            dsu2.union_sets(a, b);
        }
        else if (t == 2)
        {
            cin >> a;
            // The outputs should match, as the only difference is ranking strategy which only affects the asymptotic time complexity
            cout << "DSU1: " << dsu1.find_set(a) << endl;
            cout << "DSU2: " << dsu2.find_set(a) << endl;
        }
    }
    return 0;
}

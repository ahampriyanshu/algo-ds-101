#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

// Typedef to represent a weighted edge: (weight, (node u,node v))
typedef pair<int, pair<int,int>> edge;

// Typedef to represent a disjoint set from a node (int) vector:
typedef vector<int> disjoint_set;

/*
    Given an undirected, edge-weighted connected graph, 
    computes the edges of the minimum spanning tree. 
    We use disjoint sets to provide an efficient computation. 

    The kruskal algorithm works by selecting the lightest edge at each
    iteration. The problem with this approach is that it's possible
    to find an edge with minimum weight such that this edge creates a cycle 
    with our currently added edges. Thus, we have to find a way to check for cycles
    when we are about to add an edge. We can achieve this using disjoints sets,
    which is the solution provided below.
    Given the set of edges of the connected graph and the number of nodes
    returns the list of edges of the MST
*/
vector<edge> kruskal(vector<edge> graph, int n_nodes);

/*
    The disjoint set data structure  works by representing each subset as
    a root parent for every sub element. We choose such parent for 
    the subset, and when we add a new element to the subset, 
    we make this element a child of the root or a child of some other
    child of the root. This way, to check whether an element belongs
    to an specific subset, we have tu check if its root is the same
    as the subsets root. Here, we start with a disjoint set such that
    every element represents its own singleton subset. 
*/
disjoint_set create_set(int n);

/*
    To merge two sets together, we have to make the root of one
    of the sets be a child of an element of the second subset
*/
void set_union(disjoint_set &s, int u, int v);

/*
    The get parent function returns the root 
    of the subset containing i. Also, this function 
    flattens the parents tree by updating the parents of i 
    such that every parent points directly to the root. This way, 
    the next time we need to ask for the parent of some of these elements,
    we have to traverse a shorter distance to the root.
*/
int get_parent(disjoint_set &s, int i);

/*
    
*/
int main() {

    // Example. 
    vector<edge> graph = {
            {14, {3, 5}}, 
            {11, {1, 7}}, 
            {10, {5, 4}},
            {1,  {7, 6}},
            {2,  {8, 2}},
            {2,  {6, 5}},
            {4,  {0, 1}},
            {9,  {3, 4}},
            {8,  {1, 2}},
            {8,  {0, 7}},
            {7,  {7, 8}},
            {7,  {2, 3}},
            {6,  {8, 6}},
            {4,  {2, 5}}  
        };

    printf("Input graph: \n");
    for(auto e : graph)
        printf("(%d, %d) w: %d\n", e.second.first, e.second.second, e.first);

    vector<edge> MST = kruskal(graph, 9);

    printf("obtained graph: \n");
    for (auto e : MST )
        printf("(%d, %d) w: %d\n", e.second.first, e.second.second, e.first);

    return 0;
}

/*
    Create a new partition of n sets,
    enumerated in the range 0 <= i < n
*/
disjoint_set create_set(int n) {

    disjoint_set set(n);

    for (int i = 0; i < n; i++)
        set[i] = i;

    return set;
}

/*
    Get the parent of element i in the disjoint set s and
    flattens the disjoint set as much as it can
*/
int get_parent(disjoint_set &s, int i) {

    // If this node is its own parent, return it. 
    // This is the parent of the subset.
    if (i == s[i])
        return i;

    // Get the parent of this node's parent
    int parent = get_parent(s, s[i]);

    // update the parent and return it
    return s[i] = parent;
}

/*
    Merge two sets in one, making the set v a child of set u
*/
void set_union(disjoint_set &s, int u, int v) {

    int parent_u = get_parent(s, u);
    int parent_v = get_parent(s, v);

    // Set the parent of root of v as the parent of root of u
    s[parent_v] = parent_u;
}


/*
    Check if node u contains the node v for the set s
*/
bool contains(disjoint_set &s, int u, int v) {
    int u_parent = get_parent(s, u);
    int v_parent = get_parent(s, v);

    // The subset where u belongs contains the subset v 
    // if they have the same parent.
    return u_parent == v_parent;
}

vector<edge> kruskal(vector<edge> graph, const int n_nodes) {
    
    priority_queue<edge> edge_queue;        // Use this priority queue to sort the edges by weight within a queue
    int edge_counter = 0;           // how many edges have been added so far
    vector<edge> tree(n_nodes - 1); // the resulting spanning tree
    disjoint_set set = create_set(n_nodes); // Our disjoint set to test for cycles

    for (auto e : graph) {
        // Note that the priority queue sorts in non-increasing order, 
        // so we have to negate the weight in order to invert the order.
        edge inverted_weight_edge = {-e.first, e.second };
        edge_queue.push(inverted_weight_edge);
    } 

    // note that every spanning tree follows: 
    // number of edges = number of nodes - 1 
    while (edge_counter < n_nodes - 1) {
        edge current = edge_queue.top(); 
        edge_queue.pop();

        // each side of the edge
        int u = current.second.first; 
        int v = current.second.second;

        if ( !contains(set, u, v) ) {

            // Add this edge to our tree, since it does not creates a cycle
            tree[edge_counter++] =  { -current.first, {u,v} }; 
            // (Remember to negate the weight ^, so we have the original edge)

            // Merge the spanning tree containing u with the spanning tree containing v
            set_union(set, u, v);
        }
    }
        
    return tree;
}


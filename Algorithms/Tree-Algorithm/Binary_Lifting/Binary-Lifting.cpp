/*
Binary Lifting is an algorithm to compute the LCA of two nodes in a tree in O(logn) time complexity.
For each node we precompute some of its ancestors above it.
Specifically, let's store those ancestor in the array anc, therefore anc[i][j] represents the 2^j th
ancestor of the ith node. After pre-calculation of this array, we can determine the LCA of any two 
nodes in O(logn) time.
Time :- For each query, O(logn), n is number of nodes
Space :- O(n.logn)
*/

#include<bits/stdc++.h>
using namespace std;

/* 
timer variabel keeps the track of the order of visit of nodes in our DFS traversal
the incoming of dfs and outgoing of a function from the function stack is stored in vin & vout
*/
int n, u, v, m, tim, cnt;
vector<int> vin, vout;
vector<vector<int>> adj, anc;

void dfs(int ver, int par) {
    // time at which this particular instance is pushed into function-call stack
    vin[ver] = ++tim;

    // 2^0 = 1-st ancestore, or direct parent of the ver vertex
    anc[ver][0] = par;

    // the 2^i-th ancestor of ver is the 2^(i-1)-th ancestor of the 2^(i-1)th ancestor of ver
    // which is already calculated during the dfs traversal
    for(int i = 1; i <= cnt; ++i)
        anc[ver][i] = anc[anc[ver][i - 1]][i - 1];
    
    for(int &edge : adj[ver]) {
        if(edge == par) continue;
        dfs(edge, ver);
    }

    // time at which this particular instance is popped out of function-call stack
    vout[ver] = ++tim;
}

// intialising the ancestors of all nodes as the root
void precompute(int root) {
    tim = 0;
    cnt = floor(log2(n)) + 1;
    vin.assign(n + 1, 0);
    vout.assign(n + 1, 0);
    anc.assign(n + 1, vector<int>(cnt + 1, root));
    dfs(root, root);
}

bool is_Ancestor(int v1, int v2) {
    return (vin[v1] <= vin[v2] && vout[v1] >= vout[v2]);
}

int LCA(int v1, int v2) {
    // check if these are ancestors of each other
    if(is_Ancestor(v1, v2)) return v1;
    if(is_Ancestor(v2, v1)) return v2;

    /*
    Iterate through all the ancestors of one of the node, then two cases arise
    - If they have same ancestor, this is one of the possiblities of the answer
    - If they don't, bring the pointer of first node to this node, and start searching the ancestor 
      of this node for the lowest common one
    */
    for(int i = cnt; i >= 0; --i) {
        if(!is_Ancestor(anc[v1][i], v2))
            v1 = anc[v1][i];
    }
    return anc[v1][0];
}

/*
POINTS TO NOTE :- 
# I'll be assuming 1 based indexing of nodes
# This implementation is by assuming the tree is rooted at node 1
# adj is the adjacency list of the tree-graph
# anc is the array of ancestors of any node
*/
int main() {
    cout << "Enter the number of nodes : ";
    cin >> n;
    adj.assign(n + 1, vector<int>());
    cout << "Enter the edges :- ";
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    precompute(1);

    cout << "Enter number of queries : ";
    cin >> m;
    while(m--) {
        cout << "Enter the two vertexes : ";
        cin >> u >> v;
        cout << "The LCA of " << u << " and " << v << " is " << LCA(u, v) << endl;
    }


    return 0;
}
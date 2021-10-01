use std::vec;
/*
    The disjoint set data structure we are using to improve performance
*/
struct DisjointSet {
    partition : vec::Vec<usize>
}

/*
    Struct representing a simple weighted edge
*/
struct Edge {
    weight  : i32,
    u       : usize,
    v       : usize
}

/*
    Since we are interested in connected graphs, 
    the list of edges is enough to specify the entire graph
    for our algorithm
*/
type Graph = vec::Vec<Edge>;

fn main() {
    // Example:
    let graph = vec![
        Edge::new(13, 3, 5), 
        Edge::new(11,1, 7), 
        Edge::new(10,5, 4),
        Edge::new(1, 7, 6),
        Edge::new(2, 8, 2),
        Edge::new(2, 6, 5),
        Edge::new(4, 0, 1),
        Edge::new(9, 3, 4),
        Edge::new(8, 1, 2),
        Edge::new(8, 0, 7),
        Edge::new(7, 7, 8),
        Edge::new(7, 2, 3),
        Edge::new(6, 8, 6),
        Edge::new(4, 2, 5) 
    ];

    println!("Input graph: ");
    for e in graph.iter() {
        println!("({}, {}) W: {}", e.u, e.v, e.weight);
    }

    let tree = kruskal(graph, 9);

    println!("Obtained graph: ");
    for e in tree.iter() {
        println!("({}, {}) W: {}", e.u, e.v, e.weight);
    }
}

impl Edge {
    fn new(weight : i32, u : usize, v : usize) -> Edge {
        Edge{ weight, u, v }
    }
}

impl DisjointSet {

    /*
        The disjoint set data structure  works by representing each subset as
        a root parent for every sub element. We choose such parent for 
        the subset, and when we add a new element to the subset, 
        we make this element a child of the root or a child of some other
        child of the root. This way, to check whether an element belongs
        to an specific subset, we have tu check if its root is the same
        as the subset's root. Here, we start with a convenient disjoint set
        such that every element represents its own singleton subset. 
    */
    fn new(n_nodes : usize) -> DisjointSet {
        DisjointSet {
            partition : (0..n_nodes).collect()
        }
    }

    /*
        Get the parent of element i in the disjoint set s and
        flattens the disjoint set as much as it can.

        The get parent function returns the root 
        of the subset containing i. Also, this function 
        flattens the parents tree by updating the parents of i 
        such that every parent points directly to the root. This way, 
        the next time we need to ask for the parent of some of these elements,
        we have to traverse a shorter distance to the root.
    */
    fn get_parent(&mut self, i : usize) -> usize {

        // If this node is its own parent, return it. 
        // This is the parent of the subset.
        if self.partition[i] == i {
            return i;
        }

        // Otherwise, get the parent of this node's parent
        let parent = self.get_parent(self.partition[i]);
        self.partition[i] = parent; // flattens the tree
        parent
    }

    /*
        Merge two sets in one, making the set v a child of set u
    */
    fn union(&mut self, u : usize, v : usize) {
        let parent_u = self.get_parent(u);
        let parent_v = self.get_parent(v);

        if parent_u != parent_v {
            // Set the parent of root of v as the parent of root of u
            self.partition[parent_v] = parent_u;
        }   
    }

    /*
        Check if u's subset contains v for the set s
    */
    fn contains(&mut self, u : usize, v : usize) -> bool {

        // The subset where u belongs contains the subset v 
        // if they have the same parent.
        self.get_parent(u) == self.get_parent(v)
    }

}

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
fn kruskal(mut graph : Graph, n_nodes : usize) -> Graph {

    let mut n_edges = 0;                                      // how many edges have been added so far
    let mut tree  : Graph = vec::Vec::with_capacity(n_nodes); // The resulting spanning tree
    let mut set = DisjointSet::new(n_nodes);                  // Our disjoint set to test for cycles

    // note that we use unstable since it does not requires additional space
    // and we're conssuming the graph anyways
    graph.sort_unstable_by_key(|e| e.weight); // Sort edges by their weight

    for edge in graph {

        // if u's subset contains v, then this edge creates a cycle.
        if !set.contains(edge.u, edge.v) {

            // Merge the spanning tree containing u with the spanning tree containing v
            set.union(edge.u, edge.v);

            // Add this edge to our tree, since it does not creates a cycle:
            tree.push(edge);
            n_edges += 1;
        }

        // every spanning tree follows: 
        // number of edges = number of nodes - 1 
        if n_edges >= n_nodes - 1 {
            break;
        }
    }

    tree
}
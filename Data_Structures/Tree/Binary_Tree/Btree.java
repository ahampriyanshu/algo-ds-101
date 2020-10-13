/****************************************************
*  Author - Ayush Sharma (belphegor-s)
*  File Name - B-Tree.java
*  
*  Short Note about B-Tree -
*
*  B Tree is a specialized m-way tree that can
*  be widely used for disk access. 
*  A B-Tree of order m can have at most m-1 keys
*  and m children. One of the main reason of using 
*  B tree is its capability to store large number 
*  of keys in a single node and large key values by 
*  keeping the height of the tree relatively small.
*
******************************************************/

// Java program to illustrate the sum of two numbers

// A BTree 
class Btree {
	public BTreeNode root; // Pointer to root node
	public int t; // Minimum degree

	// Constructor (Initializes tree as empty)
	Btree(int t) {
		this.root = null;
		this.t = t;
	}

	// function to traverse the tree
	public void traverse() {
		if (this.root != null)
			this.root.traverse();
		System.out.println();
	}

	// function to search a key in this tree
	public BTreeNode search(int k) {
		if (this.root == null)
			return null;
		else
			return this.root.search(k);
	}
}

// A BTree node 
class BTreeNode {
	int[] keys; // An array of keys
	int t; // Minimum degree (defines the range for number of keys)
	BTreeNode[] C; // An array of child pointers
	int n; // Current number of keys
	boolean leaf; // Is true when node is leaf. Otherwise false

	// Constructor
	BTreeNode(int t, boolean leaf) {
		this.t = t;
		this.leaf = leaf;
		this.keys = new int[2 * t - 1];
		this.C = new BTreeNode[2 * t];
		this.n = 0;
	}

	// A function to traverse all nodes in a subtree rooted with this node
	public void traverse() {

		// There are n keys and n+1 children, travers through n keys
		// and first n children
		int i = 0;
		for (i = 0; i < this.n; i++) {

			// If this is not leaf, then before printing key[i],
			// traverse the subtree rooted with child C[i].
			if (this.leaf == false) {
				C[i].traverse();
			}
			System.out.print(keys[i] + " ");
		}

		// Print the subtree rooted with last child
		if (leaf == false)
			C[i].traverse();
	}

	// A function to search a key in the subtree rooted with this node.
	BTreeNode search(int k) { // returns NULL if k is not present.

		// Find the first key greater than or equal to k
		int i = 0;
		while (i < n && k > keys[i])
			i++;

		// If the found key is equal to k, return this node
		if (keys[i] == k)
			return this;

		// If the key is not found here and this is a leaf node
		if (leaf == true)
			return null;

		// Go to the appropriate child
		return C[i].search(k);

	}
}

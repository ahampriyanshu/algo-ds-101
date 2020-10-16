/*
 FUNCTION:       COMPLEXITY:
 - getMin()       - O(1)
 - deleteMin()    - O(log N)
 - insert()       - O(log N)
 - merge()        - O(log N)

 Node Info:
 - element
 - distance
 - parent
 - left child
 - right child

 Operations:
 - merge() is the main operation, called by deleteMin(), decreaseKey(), getMin() and insert()
 - deleteMin() removes the root of the tree and calls merge with both the left and right sons
 - getMin() returns the value of the pointer to the root
 - insert() creates a leftist heap with a single key and calls merge with the original and this new tree
 - decreaseKey() allows you to decrease the value of the first element of the pair given the second one
 */

#ifndef _LeftistHeap_
#define _LeftistHeap_

#include <cstddef>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Node {

public:
	std::pair<float, int> _elem;
	int _dist;
	Node *_parent;
	Node *_left;
	Node *_right;
	Node(std::pair<float, int> e);     			// Constructor
	Node(std::pair<float, int> e, int d, Node *p, Node *l, Node *r); // Constructor

};

class LeftistHeap {

public:
	LeftistHeap();                              // Constructor
	int getMin();             					// Returns the smallest element in the heap (root)
	void deleteMin();                			// Removes the smallest element in the heap
	void deleteMin(std::pair<float, int> &minElem); // Removes the smallest element in the heap and returns it to avoid using getMin()
	void insert(std::pair<int, int> elem); 		// Inserts the given element into the heap
	void decreaseKey(int elem, float newKey); // Modifies the value of the first value of the pair of the given element into the the newKey
	void merge(LeftistHeap &b);   				// Merges the existing heap with the given one
	bool isEmpty();                             // Tests if the heap is empty
	void emptyHeap();                           // Empties the heap
	void printHeap(); 							// Prints all the elements of the heap in decreasing order (intended use: debbugin purposes -> O(N logN))
	LeftistHeap& operator =(LeftistHeap &h);    // Deep copy of a LeftistHeap
	std::unordered_map<int, Node*>* map();		// Returns the map so it can be private

private:
	Node *_root;                      			// Root of the heap (also minimum element)
	std::unordered_map<int, Node*> *_map;       // Stores pointers to all the nodes of the heap given an element (second element of the pair)
	Node* mergeHeaps(Node *heap1, Node *heap2); // Merges both heaps, returning the root to the resulting heap
	Node* MergeRecursive(Node *heap1, Node *heap2); // Called by mergeHeaps() recursively
	void swapChildren(Node *parent); 			// Swaps the right and left childs of the given node
	void clearMem(Node *node); 					// Clears the dinamically allocated memory of the heap
	Node* cloneNode(Node *node);                // Deep copy of a node
	LeftistHeap(Node *newRoot, std::unordered_map<int, Node*> *newMap); // Constructor by copy

};

#endif

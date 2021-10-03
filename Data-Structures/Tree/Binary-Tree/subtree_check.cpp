#include<bits/stdc++.h> 
using namespace std; 

// Basic node structure of a binary tree
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
}; 

// Helper function to grow the tree
node* newNode(int data) 
{ 
    // allocate memory and assign data
	node* Node = new node(); 
	Node->data = data; 
	
	// point left and right Node pointers to NULL
	Node->left = NULL; 
	Node->right = NULL; 
	
	return(Node); 
} 

// Recursive Function to check whether trees 
// with roots as root1 and root2 
// are identical or not 
bool areIdentical(node * root1, node *root2) 
{ 
	// if both trees are null then they are 
	// identical trivially
	if (root1 == NULL && root2 == NULL) 
		return true; 

    // if either tree is identical then they 
    // non identical
	if (root1 == NULL || root2 == NULL) 
		return false; 

    // check if data of both roots is same
    if (root1->data == root2->data) {
        
        // recursive definition to traverse through
        // both trees
        return (areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
    }
    
    // if data is not same then return false
    else {
        return false;
    }
} 


// Recursive Main function which returns true if S 
// is a subtree of T, otherwise false 
bool isSubtree(node *T, node *S) 
{ 
	// base cases 
	if (S == NULL) 
		return true; 

	if (T == NULL) 
		return false; 

	// Check the tree with root as current node 
	if (areIdentical(T, S)) 
		return true; 

	// recursive definition to traverse through
	// the main tree to find identical subtree
	return isSubtree(T->left, S) || isSubtree(T->right, S); 
} 

int main() 
{ 
    // Driver code taken from GFG
    
	// TREE 1 
	/* Construct the following tree 
		26 
		/ \ 
	      10   3 
	      / \    \ 
	    4    6    3 
	     \ 
	      30 
	*/
	node *T = newNode(26); 
	T->right		 = newNode(3); 
	T->right->right = newNode(3); 
	T->left		 = newNode(10); 
	T->left->left	 = newNode(4); 
	T->left->left->right = newNode(30); 
	T->left->right	 = newNode(6); 

	// TREE 2 
	/* Construct the following tree 
		10 
		/ \ 
	       4   6 
	       \ 
		30 
	*/
	node *S = newNode(10); 
	S->right	 = newNode(6); 
	S->left	 = newNode(4); 
	S->left->right = newNode(30); 


	if (isSubtree(T, S)) 
		cout << "Tree 2 is subtree of Tree 1"; 
	else
		cout << "Tree 2 is not a subtree of Tree 1"; 

	return 0; 
} 


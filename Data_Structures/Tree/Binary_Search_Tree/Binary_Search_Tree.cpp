#include<bits/stdc++.h> 

using namespace std; 


class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
	
	
	node(int data) 
	{ 
		this->data = data; 
		this->left = NULL; 
		this->right = NULL; 
	} 
}; 

int isBSTUtil(node* node, int min, int max); 
/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
int isBST(node* node) 
{ 
	return(isBSTUtil(node, INT_MIN, INT_MAX)); //INT_MIN is minimum possible value ,INT_MAX is maximum possible value
} 

/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max) 
{ 
	/* an empty tree is BST */
	if (node==NULL) 
		return 1; 
			
	/* false if this node violates 
	the min/max constraint */
	if (node->data < min || node->data > max) 
		return 0; 
	
	/* otherwise check the subtrees recursively, 
	tightening the min or max constraint */
	return
		isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values 
		isBSTUtil(node->right, node->data+1, max); // Allow only distinct values 
} 



int main() 
{ 
	node *root = new node(4); 
	root->left = new node(2); 
	root->right = new node(5); 
	root->left->left = new node(1); 
	root->left->right = new node(3); 
	
	if(isBST(root)) 
		cout<<"Is BST"; 
	else
		cout<<"Not a BST"; 
		
	return 0; 
} 



#include <iostream>
#define MIN -1000
#define MAX  1000
using namespace std;


// helper structures and functions
struct node {
	struct node * left;
	struct node * right;
	int val;
	int maxTillNow;
	int minTillNow;
	
	node(int k): val(k), left(NULL), right(NULL), maxTillNow(MIN), minTillNow(MAX) {}
};

int max(int a, int b){
	return a > b  ? a : b;
}
int min(int a, int b){
	return a < b  ? a : b;
}







// This method sets the min and max at each node // when the node represents a root of a subtree starting from that node
// this a a resursive // dfs // implementation
void setMaxMinTillNode( node * root){
	if(root == NULL){
		return;
	}
	
	int ansMx = root->val;
	int ansMn = root->val;
	
	if( root->left != NULL){
		setMaxMinTillNode(root->left);
		ansMx = max(ansMx, root->left->maxTillNow);
		ansMn = min(ansMn, root->left->minTillNow);
	}
	
	if( root->right != NULL){
		setMaxMinTillNode(root->right);
		ansMx = max(ansMx, root->right->maxTillNow);
		ansMn = min(ansMn, root->right->minTillNow);
	}
	
	root->maxTillNow = ansMx; 
	root->minTillNow = ansMn; 
}









// this method checks the current node with the min of the right subtree and with the max of left subtree
// the is a resursive // dfs // implementation 
bool isBST(node * root){
	if( root == NULL ){
		false;
	}
	
	if( root->left == NULL && root->right == NULL){
		return true;
	}
	
	bool leftResult = true;
	if( root->left != NULL){
		if( root->val < root->left->maxTillNow){
			leftResult = false;
			return leftResult;
		}
		leftResult = isBST(root->left);
	}
	
	bool rightResult = true;
	if( root->right != NULL){
		if( root->val > root->right->minTillNow){
			rightResult = false;
			return rightResult;
		}
		rightResult = isBST(root->right);
	}
	
	return leftResult && rightResult;
}









// this is the driver function
int main() {
	// your code goes here
	node * root = new node(4);
	node * a = new node(1);
	node * b = new node(2);
	node * c = new node(3);
	node * d = new node(5);
	root->left = b;
	b->left = a;
	b->right = c;
	root->right = d;
	
	
	setMaxMinTillNode(root);
	cout << "Is the Tree a Valid BST?  Ans:" << ( isBST(root) ? "yes :)" : "nops :(") << endl;
	

	node * e = new node(1);
	d->right = e;
	
	setMaxMinTillNode(root);
	cout << "Is the Tree a Valid BST?  Ans:" << ( isBST(root) ? "yes :)" : "nops :(") << endl;
	
	
	
	e->val = 10;
	
	setMaxMinTillNode(root);
	cout << "Is the Tree a Valid BST?  Ans:" << ( isBST(root) ? "yes :)" : "nops :(") << endl;

	return 0;
}

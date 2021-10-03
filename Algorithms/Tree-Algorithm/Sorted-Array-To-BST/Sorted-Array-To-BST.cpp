#include<bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data);

/* A function that constructs Balanced
Binary Search Tree from a sorted array */
TNode* sortArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	TNode *root = newNode(arr[mid]);

	/* Recursively construct the left subtree
	and make it left child of root */
	root->left = sortArrayToBST(arr, start, mid - 1);

	/* Recursively construct the right subtree
	and make it right child of root */
	root->right = sortArrayToBST(arr, mid + 1, end);

	return root;
}

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

// Driver Code
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(i=0;i<n:i++)
	{
	  cin>>arr;
	}

	/* Convert List to BST */
	TNode *root = sortArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

	return 0;
}

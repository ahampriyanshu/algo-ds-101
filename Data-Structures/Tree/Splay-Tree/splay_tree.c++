/*
Splay tree is also a self balancing BST
All splay tree operation on approximatly O(log n) compleixty
  Searching:Searching an element in a Splay tree

*/
#include<bits/stdc++.h>
using namespace std;
//defining node class
class node
{
public:
	int val;
	node*left;
	node*right;
};
//adding node into splay tree
node* newNode(int key)
{
	node* temp= new node();
	temp->val=key;
	temp->left=temp->right=NULL;
	return (temp);
}
//this help to rotate right tree
node *right_rotate(node*val)
{
	node*temp=val->left;
	val->left=temp->right;
	temp->right=val;
	return temp;
}
//this help to rotate left tree
 
 node *left_rotate(node*val)
 {
 	node*temp=val->right;
 	val->right=temp->left;
 	temp->left=val;
 	return temp;
 }
 //Splay tree function
node *splay(node *root, int key)
{
    
    if (root == NULL || root->val == key)
        return root;
 
    
    if (root->val > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
 
        
        if (root->left->val > key)
        {
        
            // key as root of left-left
            root->left->left = splay(root->left->left, key);
 
            
            root = right_rotate(root);
        }
        else if (root->left->val< key) 
        {
          
            root->left->right = splay(root->left->right, key);
 
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = left_rotate(root->left);
        }
 
        // Do second rotation for root
        return (root->left == NULL)? root: right_rotate(root);
    }
    else 
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
 
        
        if (root->right->val > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
 
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = right_rotate(root->right);
        }
        else if (root->right->val < key)
        {
           
            // right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = left_rotate(root);
        }
 
        // Do second rotation for root
        return (root->right == NULL)? root: left_rotate(root);
    }
 	

 
}

node *search(node *root, int key)
{
    return splay(root, key);
}


void preOrder(node *root)
{
    if (root != NULL)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}





int main()
{
	//creating a splay tree 
	node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
 
    root = search(root, 20);
    cout << "Splay tree is \n";
    preOrder(root);
    return 0;

}
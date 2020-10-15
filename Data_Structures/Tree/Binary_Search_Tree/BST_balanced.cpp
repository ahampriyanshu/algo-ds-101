#include <iostream>
#include <cmath>
 
using namespace std;
int mx = -1e9-10, mn = 1e9+10, c = 0;
struct node
{
    int key;
    node * left;
    node * right;
 	bool isBalancedNode;
    node(int k) {
        key = k;
        left = right = NULL;
        isBalancedNode = true;
    }
};
 
struct BST
{
    node * root;
    int cnt;
 
    BST() {
        cnt = 0;
        root = NULL;
    }
 
    node * add(node * root, int x) {
       
        if(root == NULL)
        {
            node * n = new node(x);
            root = n;
            cnt++;
        }
        else if(x < root->key)
        {
            root->left = add(root->left, x);
        }
        else if(x > root->key)
        {
            root->right = add(root->right, x);
        }
        return root;
    }



    void inorder(node * x) {
        if(x != NULL) {
            inorder(x->left);
            cout << x->key << ' ' << x->isBalancedNode << '\n';
            inorder(x->right);
        }
    }

    int balance(node * root, int h) {
    	if(root == NULL) return h;
    	int l = balance(root->left, h+1);
    	int r = balance(root->right, h+1);
    	root->isBalancedNode = (abs(l - r) < 2);
    	return max(l, r);
    }

    bool isBalanced(node * x) {
    	if(x == NULL) return true;
    	return x->isBalancedNode && isBalanced(x->right) && isBalanced(x->left);
    }
};
int main() {
    BST myTree;
    int x, cnt=0;
    while(cin>>x && x!=0)
    {
        myTree.root = myTree.add(myTree.root, x);
    }
    myTree.balance(myTree.root, 0);
    
    cout <<(myTree.isBalanced(myTree.root) ? "YES" : "NO");

    return 0;
}

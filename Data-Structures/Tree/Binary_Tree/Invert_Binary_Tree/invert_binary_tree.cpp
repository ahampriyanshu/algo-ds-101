#include<bits/stdc++.h> 
using namespace std; 
//Definition for binary tree-
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
};
//Utility function-
struct TreeNode* newNode(int val) { 
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    node->val = val; 
    node->left = NULL; 
    node->right = NULL;
    return(node); 
} 
//Inverting Binary Tree using recursion-
void invert(TreeNode* A){
    if(A==NULL) return;
    invert(A->left);
    TreeNode* t1=A->left;
    invert(A->right);
    TreeNode* t2=A->right;
    A->left=t2;
    A->right=t1;
}
TreeNode* invertTree(TreeNode* root) {
    invert(root);
    return root;
}
int main() { 
    struct TreeNode *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);
    //Convert tree to its mirror-
    root = invertTree(root); 
    return 0;  
} 

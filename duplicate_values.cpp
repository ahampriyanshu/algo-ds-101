#include <bits/stdc++.h> 
using namespace std; 
//Definition of Binary Tree node-
struct TreeNode { 
    int val; 
    struct TreeNode* left; 
    struct TreeNode* right; 
}; 
//Utility function-
struct TreeNode* newNode(int val) { 
    struct TreeNode* node = new TreeNode; 
    node->val = val; 
    node->left = node->right = NULL; 
    return (node); 
} 

bool find(TreeNode* root, unordered_set<int> &s) { 
    // If tree is empty, there are no duplicates 
    if (root == NULL) 
       return false; 
    // If current node's data is already present, ie. duplicate found-
    if (s.find(root->val) != s.end()) 
       return true; 
    // If not found, insert current node- 
    s.insert(root->data); 
    // Recursively check in left and right subtrees-
    return find(root->left, s)||find(root->right, s); 
} 

bool isDup(struct TreeNode* root) { 
    unordered_set<int> s; 
    return find(root, s); 
}

int main() { 
    struct TreeNode* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    if (isDup(root)) 
        return 1;
    return 0; 
} 

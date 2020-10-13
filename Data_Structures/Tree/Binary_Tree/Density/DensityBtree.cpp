/*Density of Binary Tree = Size / Height */

#include<bits/stdc++.h> 
   
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
   
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
  
int heighAndSize(Node* node, int &size) 
{ 
    if (node==NULL) 
        return 0; 
  
    int l = heighAndSize(node->left, size); 
    int r = heighAndSize(node->right, size); 
  
    size++; 
    return (l > r) ? l + 1 : r + 1; 
} 
  
float density(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
  
    int size = 0; // To store size 
  
    int _height = heighAndSize(root, size); 
  
    return (float)size/_height; 
} 
  
int main() 
{ 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    printf("Density of given binary tree is %f", 
           density(root)); 
  
    return 0; 
} 

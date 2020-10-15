#include <stdio.h> 
#define MARKER -1 

struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 

Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
void serialize(Node *root, FILE *fp) 
{ 
    if (root == NULL) 
    { 
        fprintf(fp, "%d ", MARKER); 
        return; 
    } 
  
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp); 
} 

int main() 
{ 
    struct Node *root        = newNode(32); 
    root->left               = newNode(12); 
    root->right              = newNode(23); 
    root->left->left         = newNode(40); 
    root->left->right        = newNode(33); 
    root->left->right->left  = newNode(50); 
    root->left->right->right = newNode(45); 
  
    FILE *fp = fopen("tree.txt", "w"); 
    if (fp == NULL) 
    { 
        puts("Error: Could not open file!"); 
        return 0; 
    } 
    serialize(root, fp); 
    fclose(fp);   
    return 0; 
} 

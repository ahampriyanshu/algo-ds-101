#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree Node has key, pointer to left and right children */
struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 
  
/* Given a binary tree, print nodes from level number 'low' to level 
   number 'high'*/
void printLevels(Node* root, int low, int high) 
{ 
    queue <Node *> Q; 
  
    Node *marker = new Node; // Marker node to indicate end of level 
  
    int level = 1;   // Initialize level number 
  
    // Enqueue the only first level node and marker node for end of level 
    Q.push(root); 
    Q.push(marker); 
  
    // Simple level order traversal loop 
    while (Q.empty() == false) 
    { 
        // Remove the front item from queue 
        Node *n = Q.front(); 
        Q.pop(); 
  
        // Check if end of level is reached 
        if (n == marker) 
        { 
            // print a new line and increment level number 
            cout << endl; 
            level++; 
  
            // Check if marker node was last node in queue or 
            // level number is beyond the given upper limit 
            if (Q.empty() == true || level > high) break; 
  
            // Enqueue the marker for end of next level 
            Q.push(marker); 
  
            // If this is marker, then we don't need print it 
            // and enqueue its children 
            continue; 
        } 
  
        // If level is equal to or greater than given lower level, 
        // print it 
        if (level >= low) 
            cout << n->key << " "; 
  
        // Enqueue children of non-marker node 
        if (n->left != NULL)  Q.push(n->left); 
        if (n->right != NULL) Q.push(n->right); 
    } 
} 
  
/* Helper function that allocates a new Node with the 
   given key and NULL left and right pointers. */
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    // Let us construct the BST shown in the above figure 
    struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
    cout << "Level Order traversal between given two levels is"; 
    printLevels(root, 2, 3); 
  
    return 0; 
} 

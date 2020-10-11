/* Density of Binary Tree = Size / Height */

#include<stdio.h> 		//For standard input / output operations
#include<stdlib.h>		//For dynamic declaration of Node using malloc

struct Node { 	//Struct for a Node in the tree
    int data; 	//Data stored in this node
    struct Node *left, *right; 		//Pointer to left and right child
}; 

struct Node* newNode(int data) {	//Function for defining a New Node
    struct Node* node = malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 	//Initialize left and right child as 0
    return node; 
} 

int heightAndSize(struct Node* node, int *size) { 
    if (node==NULL)	//Left node 
        return 0; 

    int left_child_height = heightAndSize(node->left, size); 	//Recursively calls of the function for its left child
    int right_child_height = heightAndSize(node->right, size); 	//Recursively calls of the function for its right child

    *size=*size+1; 	//Increments size by 1 on traversal of each node
    return (left_child_height > right_child_height) ? left_child_height + 1 : right_child_height + 1; //Returns the larger height among it's left and right child and adds 1 to account for itself
} 

float density(struct Node* root){ 	//Function to calculate density by passing root of tree
    if (root == NULL) 	//Incase root is Null , tree will be empty and hence density is 0
        return 0; 

    int size, tree_height;
    size = 0; 	//Initialize size of the tree as 0
    tree_height = heightAndSize(root, &size); //Calls function to find height and size of the tree (returns height and increments size by address of parameter)
    return (float)size/tree_height; 
} 

int main(){ 
    struct Node* root = newNode(1); 	//Root of tree 
    root->left = newNode(2); 			//Child Node
    root->right = newNode(3); 			//Child Node
    root->right->left = newNode(4);		//Child Node

    // For current example, height = 3 and size = 4 hence density should be 1.3333
    printf("Density of given binary tree is %f", density(root)); 	//Prints density
    return 0; 
} 
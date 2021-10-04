#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
	malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
              return(node); 
} 
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
   
     printPostorder(node->left); 
 
     printPostorder(node->right); 
  
     printf("%d ", node->data); 
} 

int main() 
{ 
	struct node *root = newNode(1); 
	root->left = newNode(2); 
	root->right= newNode(3); 
	root->left->left= newNode(4); 
	root->left->right = newNode(5); 

	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorder(root);  
              getchar(); 
	return 0; 
}

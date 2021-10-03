#include <bits/stdc++.h> 
  
using namespace std; 
  

struct TNode{ 
    int key; 
    struct TNode *left, *right; 
}; 
  
 
TNode* newTNode(int key) 
{ 
    TNode* temp = new TNode; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
 
struct LLNode{ 
    int key; 
    struct LLNode *prev, *next; 
}; 
  
 
LLNode* newLLNode(int key) 
{ 
    LLNode* temp = new LLNode; 
    temp->key = key; 
    temp->prev = temp->next = NULL; 
    return temp; 
} 
  
 
void verticalSumDLLUtil(TNode *root, LLNode *sumNode) 
{ 
    

    sumNode->key = sumNode->key + root->key; 
  
     
    if(root->left) 
    { 
        if(sumNode->prev == NULL) 
        { 
            sumNode->prev = newLLNode(0); 
            sumNode->prev->next = sumNode; 
        } 
        verticalSumDLLUtil(root->left, sumNode->prev); 
    } 
  
    
    if(root->right) 
    { 
        if(sumNode->next == NULL) 
        { 
            sumNode->next = newLLNode(0); 
            sumNode->next->prev = sumNode; 
        } 
        verticalSumDLLUtil(root->right, sumNode->next); 
    } 
} 
  


void verticalSumDLL(TNode* root) 
{ 
    
    LLNode* sumNode = newLLNode(0); 
  
     
    verticalSumDLLUtil(root, sumNode); 
  
    
    while(sumNode->prev != NULL){ 
        sumNode = sumNode->prev; 
    } 
  
    while(sumNode != NULL){ 
        cout << sumNode->key <<" "; 
        sumNode = sumNode->next; 
    } 
} 
  
int main() 
{ 
    
    TNode *root = newTNode(1); 
    root->left = newTNode(2); 
    root->right = newTNode(3); 
    root->left->left = newTNode(4); 
    root->left->right = newTNode(5); 
    root->right->left = newTNode(6); 
    root->right->right = newTNode(7); 
  
    cout << "Vertical Sums are\n"; 
    verticalSumDLL(root); 
    return 0; 
} 
  

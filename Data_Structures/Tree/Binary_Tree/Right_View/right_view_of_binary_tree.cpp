#include<bits/stdc++.h> 
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
//Utility function to create Tree nodes
TreeNode* newNode(int val) { 
    TreeNode *temp = new TreeNode; 
    temp->val = val; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
//The task is equivalent to returning the last value in each level of the tree, ie. similar to Breadth First Traversal
vector<int> getRightView(TreeNode* root) {
    vector<int>answer;
    queue<TreeNode*>Q;          
    TreeNode* temp;
    Q.push(root);
    //NULL node is used to demarkate separate levels of the tree-
    Q.push(NULL);              
    //BFS type approach using queue-
    while(!Q.empty()){         
        temp=Q.front();
        Q.pop();
        if(temp!=NULL){
           if(temp->left!=NULL) 
              Q.push(temp->left);
           if(temp->right!=NULL) 
              Q.push(temp->right);
           if(Q.front()==NULL){             //we are at the end of the current level, ie. current node's value is required in the answer
              answer.push_back(temp->val);
              Q.pop();
              Q.push(NULL);
           }
       }
    }
    return answer;
}
int main() { 
    //constructing the tree-
    TreeNode* root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(8); 
    root->right->right = newNode(15); 
    root->right->left = newNode(12); 
    root->right->right->left = newNode(14); 
    vector<int> RightViewOfBTree = getRightView(root);
    //printing the vector containing right view of this tree-
    for(int i=0; i<RightViewOfBTree.size(); i++)
        cout<<RightViewOfBTree[i]<<" ";
    cout<<"\n";
} 

#include<bits/stdc++.h> 
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

//The task is equivalent to returning the last value in each level of the tree, ie. similar to Breadth First Traversal
vector<int> rightView(TreeNode* root) {
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

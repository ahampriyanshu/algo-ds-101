//Definition for binary tree-
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

};
//Utility function-
TreeNode *newNode(int val) { 
    TreeNode *temp = new Node; 
    temp->val  = val; 
    temp->left  = temp->right = NULL; 
    return (temp); 
} 

int check(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL)
       return 1;
    //one is NULL, other is not, ie. Asymmetric-
    if(A==NULL || B==NULL)
       return 0;
    //unequal values, ie. Asymmetric-
    if(A->val != B->val)   
       return 0;
    //checking all subtrees using recursion-
    if(check(A->left, B->right) && check(A->right, B->left))
       return 1;
    //Asymmetric-
    return 0;              
}
int isSymmetric(TreeNode* A) {
    //null tree is considered symmetric-
    if(A==NULL)
       return 1;
    return check(A->left, A->right);
}

int main() { 
    TreeNode *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(4); 
    root->right->right = newNode(3); 
  
    return isSymmetric(root);
} 

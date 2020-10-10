//Question Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=-1e8;
    int maxPathSum_(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftNodeToNode=maxPathSum_(root->left);
        int rightNodeToNode=maxPathSum_(root->right);
        
        int max_=max(leftNodeToNode,rightNodeToNode)+root->val;
        maxSum= max(maxSum,max(leftNodeToNode+rightNodeToNode+root->val,max(root->val,max_)));
        
        return max(max_,root->val);
    }
    int maxPathSum(TreeNode* root) {
        maxPathSum_(root);
        
        return maxSum;
    }
};

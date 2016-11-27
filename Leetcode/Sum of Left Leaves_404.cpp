/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
       return helper(root);
    }
    int helper(TreeNode* node){
        if(node == NULL) return 0;
        int sum = 0;
        if(node->left != NULL && node->left->left == NULL && node->left->right == NULL) 
        	sum += node->left->val;
        else 
        	sum += helper(node->left);
        return sum + helper(node->right);
    }
};
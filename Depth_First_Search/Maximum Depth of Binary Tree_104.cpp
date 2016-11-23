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
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode* node){
        if(node == NULL) return 0;
        return 1+max(helper(node->left), helper(node->right));
    }
};
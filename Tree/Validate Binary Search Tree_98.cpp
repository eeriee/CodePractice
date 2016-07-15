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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
    
    bool helper(TreeNode* node, int min, int max){
        if(node == NULL) return true;
        
        int val = node->val;
        if(val < min || val > max || (val == INT_MIN && node->left != NULL) 
        || (val == INT_MAX && node->right !=NULL)) return false;
        
        return helper(node->left, min, val-1) && helper(node->right, val+1, max);
        
    }
};

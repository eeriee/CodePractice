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
    int countUnivalSubtrees(TreeNode* root) {
        return visit(root, 0);
    }
    int visit(TreeNode* node, int len){
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return 1 + len;
        
        int val = node->val, lLen = 0, rLen = 0;
        if(node->left != NULL && node->right != NULL){
            if(node->left->val== val && node->right->val== val)
                lLen = len + 1;
        }else if(node->left == NULL){
            if(node->right->val == val)
                rLen = len + 1;
        }else{
            if(node->left->val== val)
                lLen = len + 1;
        }
        
        return visit(node->left, lLen) + visit(node->right, rLen);
    }
};

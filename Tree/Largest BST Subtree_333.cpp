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
    int largestBSTSubtree(TreeNode* root) {
        size = 0;
        if(isBST(root, INT_MIN, INT_MAX))
            return size;
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    
    bool isBST(TreeNode* root, int min, int max){
        if(root == NULL) return true;
        int val = root->val;
        ++size;
        if(val < min || val > max || (val == INT_MIN && root->left != NULL) || (val == INT_MAX && root->right != NULL)) return false;
        return isBST(root->left, min, val-1) && isBST(root->right, val+1, max);
    }
    
    int size = 0;
};

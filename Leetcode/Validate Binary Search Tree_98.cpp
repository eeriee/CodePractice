/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//iterative - use inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        while(root != NULL || !stk.empty()){
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
//recursive1 - no int_max and int_min
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
//recursive2
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

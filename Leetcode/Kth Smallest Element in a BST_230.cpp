/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(k)??? determine by the left side
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int res = 0;
        stack<TreeNode*> stk;
        while(root != NULL || !stk.empty()){
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            --k;
            if(k == 0){
                res = root->val;
                break;
            }
            root = root->right;
        }
        return res;
    }
};
 //my solu. O(n)
class Solution {
public:
    void helper(TreeNode* root, int& k, int& res){
        if(root == NULL) return;
        helper(root->left, k, res);
        --k;
        if(k == 0){
            res = root->val;
        }
        helper(root->right, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        helper(root, k, res);
        return res;
    }
};
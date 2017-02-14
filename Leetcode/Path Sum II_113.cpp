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
    void helper(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum, int targetSum){
        if(root == NULL) return;
        path.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum) res.push_back(path);
        }else{
            helper(res, path, root->left, sum, targetSum);
            helper(res, path, root->right, sum, targetSum);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path, root, 0, sum);
        return res;
    }
};
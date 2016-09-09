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
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper(root);
        return leaves;
    }
    
    int helper(TreeNode* node){
        if(node == NULL) return -1;
        int height = max(helper(node->left), helper(node->right)) + 1;
        if(height > (int)leaves.size() - 1) leaves.push_back(vector<int>());
        leaves[height].push_back(node->val);
        return height;
    }
    vector<vector<int>> leaves;
};
//level, height, depth http://typeocaml.com/2014/11/26/height-depth-and-level-of-a-tree/

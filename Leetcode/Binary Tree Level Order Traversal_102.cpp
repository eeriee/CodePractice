/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> orders;
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                orders.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            res.push_back(orders);
        }
        return res;
    }
};

//preorder dfs
class Solution {
public:
    vector<vector<int>> res;
    void buildOrder(TreeNode* node, int depth){
        if(node == NULL) return;
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(node->val);
        buildOrder(node->left, depth+1);
        buildOrder(node->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildOrder(root, 0);
        return res;
    }
};
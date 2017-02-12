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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> currlevel;
        currlevel.push(root);
        bool ltor = true;
        TreeNode* curr;
        while(!currlevel.empty()){
            int len = currlevel.size();
            vector<int> level(len);
            for(int i = 0; i < len; ++i){
                curr = currlevel.front();
                currlevel.pop();
                if(ltor) level[i] = curr->val;
                else level[len-1-i] = curr->val;
                if(curr->left) currlevel.push(curr->left);
                if(curr->right) currlevel.push(curr->right);
            }
            ltor = !ltor;
            res.push_back(level);
        }
        return res;
    }
};
 // my solu
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        stack<TreeNode*> currlevel;
        currlevel.push(root);
        bool odd = true;
        TreeNode* curr;
        while(!currlevel.empty()){
            stack<TreeNode*> nextlevel;
            vector<int> level;
            while(!currlevel.empty()){
                curr = currlevel.top();
                currlevel.pop();
                level.push_back(curr->val);
                if(odd){
                    if(curr->left) nextlevel.push(curr->left);
                    if(curr->right) nextlevel.push(curr->right);
                }else{
                    if(curr->right) nextlevel.push(curr->right);
                    if(curr->left) nextlevel.push(curr->left);
                }
            }
            swap(currlevel, nextlevel);
            odd = !odd;
            res.push_back(level);
        }
        return res;
    }
};
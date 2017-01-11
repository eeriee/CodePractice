/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// new one
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        int maxLen = 1;
        helper(root, root->val, maxLen, 0);
        return maxLen;
    }
    void helper(TreeNode* node, int prev, int& maxLen, int curLen){
        if(node == NULL) return;
        int val = node->val;
        if(prev == val - 1){
            maxLen = max(maxLen, curLen+1);
        }else{
            curLen = 0;
        }
        ++curLen;
        helper(node->left, val, maxLen, curLen);
        helper(node->right, val, maxLen, curLen);
    }
};
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, 0, root->val);
        return maxLen;
    }
    void dfs(TreeNode* node, int len, int val){
        if(node == NULL) return;
        if (node->val == val) ++len;
        else len = 1;
        maxLen = max(len, maxLen);
        dfs(node->left, len, node->val+1);
        dfs(node->right, len, node->val+1);
    }
    int maxLen = 0;
};
//old one
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        maxLen = 0;
        if(root != NULL){
            ++maxLen;
            findConsecutivePath(root, 1);
        }
        return maxLen;
    }
    void findConsecutivePath(TreeNode* node, int len){
        int pVal = node->val;
        if(node->left != NULL){
            int lVal = node->left->val;
            if(lVal == pVal+1){
                maxLen = max(1+len, maxLen);
                findConsecutivePath(node->left, 1+len);
            }else{
                findConsecutivePath(node->left, 1);
            }
        }
        if(node->right != NULL){
            int rVal = node->right->val;
            if(rVal == pVal+1){
                maxLen = max(1+len, maxLen);
                findConsecutivePath(node->right, 1+len);
            }else{
                findConsecutivePath(node->right, 1);
            }
        }
    }
    int maxLen;
};


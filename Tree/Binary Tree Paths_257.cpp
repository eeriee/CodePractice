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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return{};
        vector<string> paths;
        getPath(root, "", paths);
        return paths;
    }
    
    void getPath(TreeNode* node, string str, vector<string>& paths){
        str += to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            paths.push_back(str);
        }else{
            str += "->";
            if(node->left != NULL)
                getPath(node->left, str, paths);
            if(node->right != NULL)
                getPath(node->right, str, paths);
        }
    }
};
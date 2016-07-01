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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL, *node = root;
        while(node != NULL){
            if(node->val <= p->val){
                node = node->right;
            }else{
                succ = node;
                node = node->left;
            }
        }
        return succ;
    }
};
/*
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right != NULL){
            return minVal(p->right);
        }
        
        TreeNode* succ = NULL, *node = root;
        while(node != NULL){
            if(node->val < p->val){
                node = node->right;
            }else if(node->val > p->val){
                succ = node;
                node = node->left;
            }else break;
        }
        return succ;
    }
    
    TreeNode* minVal(TreeNode* node){
        TreeNode* p = node;
        while(p->left != NULL){
            p = p->left;
        }
        return p;
    }
};
*/

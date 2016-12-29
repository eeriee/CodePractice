/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//quick way but cannot get the correct answer if one node is not in the tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!= NULL && right!= NULL) return root;
        return left == NULL? right: left;
    }
};


//stupid way, discuss different cases;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q || findDescendant(p,q)){
            return p;
        }
        if(findDescendant(q, p)) return q;
        TreeNode* ans;
        findAncestor(ans, root, p, q);
        return ans;
    }
    bool findAncestor(TreeNode*& ans, TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return false;
        if(node == p || node == q){
            return true;
        }
        bool leftRes = findAncestor(ans, node->left, p, q);
        bool rightRes = findAncestor(ans, node->right, p, q);
        if(leftRes && rightRes){
            ans = node;
            return false;
        }
        return leftRes || rightRes;
    }
    
    bool findDescendant(TreeNode* node, TreeNode* des) {
        if(node == NULL) return false;
        if(node == des){
            return true;
        } 
        return findDescendant(node->left, des) || findDescendant(node->right, des);
    }
};
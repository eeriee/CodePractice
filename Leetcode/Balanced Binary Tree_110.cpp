/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    int getHeight(TreeNode* node){
        if(node == NULL) return 0;
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight-rightHeight) < 1) return -1;
        return max(leftHeight, rightHeight)+1;
    }
};

//For the current node root, calling depth() for its left and right children actually has to access all of its children, thus the complexity is O(N). We do this for each node in the tree, so the overall complexity of isBalanced will be O(N^2). This is a top down approach.
//O(NlogN), for each level you are doing a total scan of N, and there are logN levels.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* node){
        if(node == NULL) return 0;
        return 1+max(getDepth(node->left), getDepth(node->right));
    }
};
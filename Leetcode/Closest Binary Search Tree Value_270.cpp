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
    int closestValue(TreeNode* root, double target) {
        ans = root->val;
        diff = abs(target - ans);
        return search(root, target);
    }
    
    int search(TreeNode* root, double key){
        if(root == NULL) return ans;
        int val = root->val;
        
        if(key == val) return val;
        
        if(diff > abs(val - key)){
            diff = abs(val - key);
            ans = val;
        }
        
        if(key < val) return search(root->left, key);
        else return search(root->right, key);
    }
    double diff;
    int ans;
};

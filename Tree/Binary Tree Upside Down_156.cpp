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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        map<int, int> l,r;
        int h = 0;
        while(root != NULL){
            l[h] = root->val;
            if(root->right != NULL)
                r[h+1] = root->right->val;
            root = root->left;
            ++h;
        }
        
        --h;
        TreeNode* newRoot;
        
        if(h > -1){
            newRoot = new TreeNode(l[h]);
        }else
            newRoot = NULL;
            
        TreeNode* p = newRoot;
        
        while(h > 0){
            if(r.find(h) != r.end()){
                p->left = new TreeNode(r[h]);
            }
            p->right = new TreeNode(l[--h]);
            p = p->right;
        }
        return newRoot;
    }
};

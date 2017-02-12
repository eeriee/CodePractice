//can use HashMap to cache the inorder[] position. This can reduce your solution from 20ms to 5ms.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        return preTravelsal(preorder, inorder, mp, 0, 0, inorder.size()-1);
    }
    TreeNode* preTravelsal(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp, int preindex, int instart, int inend){
        if(preindex >= preorder.size() || instart > inend) return NULL;
        int target = preorder[preindex];
        TreeNode* root = new TreeNode(target);
        int inindex = mp[target]; // index of curr root in the inorder tree
        /* use map instead
        for(int i = instart; i <= inend; ++i){
            if(preorder[preindex] == inorder[i]){
                inindex = i;
                break;
            }
        }*/
        //in [instart, inindex-1] are left tree
        //in [inindex+1, inend] are right tree
        root->left = preTravelsal(preorder, inorder, mp, preindex+1, instart, inindex-1);
        root->right = preTravelsal(preorder, inorder, mp, preindex+inindex-instart+1, inindex+1, inend);
        return root;
    }
};
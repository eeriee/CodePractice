// iterator
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        while(root != NULL || !stk.empty()){
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> tr;
        while(root != NULL || !st.empty()){
            if(root != NULL){
                st.push(root);
                root = root -> left;
            }else{
                root = st.top();
                tr.push_back(root -> val);
                st.pop();
                root = root -> right;
            }
        }
        return tr;
    }
};

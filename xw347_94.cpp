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

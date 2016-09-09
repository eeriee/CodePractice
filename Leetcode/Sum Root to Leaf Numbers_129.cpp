class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helperSum(root, 0);
    }
    int helperSum(TreeNode* root, int sum){
        if(root == NULL){
            return 0;
        }else if(root->left == NULL && root->right == NULL){
            return 10*sum + root->val;
        }else{
            sum = sum*10 + root->val;
            return helperSum(root->left, sum) + helperSum(root->right, sum);
        }
    }
};

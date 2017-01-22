/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //clear solu
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        return buildTree(nums, 0, nums.size()-1);
    }
    TreeNode* buildTree(vector<int>& nums, int low, int high){
       if(low > high) return NULL;
       int mid = (low+high)/2;
       TreeNode* node = new TreeNode(nums[mid]);
       node->left = buildTree(nums, low, mid-1);
       node->right = buildTree(nums, mid+1, high);
       return node;
    }
};
// my first solu
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        TreeNode* root = new TreeNode(nums[n/2]);
        buildTree(root, nums, 0, n/2, n);
        return root;
    }
    void buildTree(TreeNode* node, vector<int>& nums, int low, int i, int high){
        if(low+(i-low)/2 < i){
            node->left = new TreeNode(nums[low+(i-low)/2]);
            buildTree(node->left, nums, low, low+(i-low)/2, i);
        }
        if((high-i)/2 > 0){
            node->right = new TreeNode(nums[i+(high-i)/2]);
            buildTree(node->right, nums, i+1, i+(high-i)/2, high);
        }
    }
};
// iterative
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; ++i){
            ans[i] = ans[i-1]*nums[i-1]; 
        }
        int product = 1;
        for(int i = n-1; i >= 0; --i){
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }
};

//recursive
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        calProduct(ans, nums, 0, 1);
        return ans;
    }
    
    int calProduct(vector<int>& ans, vector<int>& nums, int i, int pre){
        if(i == nums.size()-1){
            ans[i] = pre;
            return nums[i];
        }
        int product = calProduct(ans, nums, i+1, pre*nums[i]);
        ans[i] = pre*product;
        return product*nums[i];
    }
};
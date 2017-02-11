class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        int res = sums[0];
        for(int i = 1; i < n; ++i){
            sums[i] = max(sums[i-1], 0) + nums[i];
            res = max(res, sums[i]);
        }
        return res;
    }
};
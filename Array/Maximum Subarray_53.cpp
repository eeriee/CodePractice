class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n+1);
        for(int i = 1; i <= n; ++i){
            sums[i] = max(sums[i-1], 0) + nums[i-1];
        }
        int res = INT_MIN;
        for(int i = 1; i <= n; ++i){
            res = max(res, sums[i]);
        }
        return res;
    }
};
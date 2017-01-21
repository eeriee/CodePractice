//DP. O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[j]+1, dp[i]);
                    res = max(dp[i], res);
                }
            }
        }
        return res;
    }
};
//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        vector<int> LIS;
        for(int i = 0; i < n; ++i){
            auto pos = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if(pos == LIS.end()) LIS.push_back(nums[i]);
            else *pos = nums[i];
        }
        return LIS.size();
    }
};

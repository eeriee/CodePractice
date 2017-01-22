// O(n) time, O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int preNo = 0, preYes = 0;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = preNo;
            preNo = max(preNo, preYes);
            preYes = tmp + nums[i];
        }
        return max(preNo, preYes);
    }
};
// O(n) time, O(n) space
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size()+1);
        int res = dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); ++i){
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
            res = max(dp[i], res);
        }
        return res;
    }
};
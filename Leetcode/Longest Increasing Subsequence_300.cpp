//DP. O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        vector<int> LIS(n);
        for(int i = 0; i < n; ++i){
            LIS[i] = 1;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }
        int maxLen = 1;
        for(int i = 0; i < n; ++i){
            maxLen = max(maxLen, LIS[i]);
        }
        return maxLen;
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

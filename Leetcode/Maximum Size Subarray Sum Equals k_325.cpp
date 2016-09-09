class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = 0, sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(sum == k)
                len = i+1;
            else if(mp.count(sum-k))
                len = max(len, i - mp[sum-k]);
                
            if(!mp.count(sum)) 
                mp.insert({sum, i});
        }
        return len;
    }
};

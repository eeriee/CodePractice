class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            int curr = nums[i], res = target - curr;
            if(mp.find(res) != mp.end()) return {mp[res], i};
            mp.insert({curr,i});
        }
        return {};
    }
};

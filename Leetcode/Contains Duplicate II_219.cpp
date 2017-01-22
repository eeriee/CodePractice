// set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> se;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(i > k) se.erase(nums[i-k-1]);
            if(se.find(num) != se.end()) return true;
            se.insert(num);
        }
        return false;
    }
};
// mp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(mp.find(num) != mp.end() && i - mp[num] <= k) return true;
            mp[num] = i;
        }
        return false;
    }
};
//O(n) using bucket of size t+1 and then slide window of k 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 0) return false;
        unordered_map<long, long> mp;
        long w = t+1;
        for(int i = 0; i < nums.size(); ++i){
            long bucket = ((long)nums[i] - INT_MIN)/w;
            if(mp.count(bucket) ||
            mp.count(bucket-1) && abs(nums[i] - mp[bucket-1]) < w ||
            mp.count(bucket+1) && abs(nums[i] - mp[bucket+1]) < w ) return true; 
            //When there are duplicate keys, the function will return true immediately.
            mp[bucket] = nums[i];
            if(i >= k) mp.erase(((long)nums[i-k] - INT_MIN)/w);
        }
        return false;
    }
};
//nlog(k). use BST.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 0) return false;
        set<long> se;
        for(int i = 0; i < nums.size(); ++i){
            set<long>::iterator it = se.lower_bound((long)nums[i]-t);
            if(it != se.end() && abs((long)*it - nums[i]) <= t) {
                return true;
            }
            se.insert(nums[i]);
            if(i >= k) se.erase(nums[i-k]);
        }
        return false;
    }
};
//up-bottom
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> visited(target+1, -1);
        visited[0] = 1;
        return helper(nums, target, visited);
    }
    int helper(vector<int>& nums, int target, vector<int>& visited){
        if(visited[target] != -1) return visited[target];
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(target >= nums[i]){
                res += helper(nums, target-nums[i], visited);
            }
        }
        visited[target] = res;
        return res;
    }
};

// bottom-up
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> comb(target+1, 0);
        comb[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int num: nums){
                if(num <= i)
                    comb[i] += comb[i-num];
            }
        }
        return comb[target];
    }
};
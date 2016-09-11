class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n == 0){
            res.push_back(nums);
        }else{
            sort(nums.begin(), nums.end());
            helper(res, nums, {});
        }
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> nums, vector<int> item){
        int n = nums.size();
        if(n == 1){
            item.push_back(nums[0]);
            res.push_back(item);
            return;
        }
        int i = 0;
        while(i < n){
            int num = nums[i];
            item.push_back(num);
            nums.erase(nums.begin()+i); //use it to record visited node
            helper(res, nums, item);
            item.pop_back();
            nums.insert(nums.begin()+i, num);
            while((++i) < n && nums[i] == num);
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n == 0){
            res.push_back(nums);
        }else{
            sort(nums.begin(), nums.end());
            helper(res, nums, 0, n);
        }
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> nums, int start, int n){
        if(start == n-1 ){
            res.push_back(nums);
            return;
        }
        for(int i = start; i < n; ++i){
            if(i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]); //start from nums[i]
            helper(res, nums, start+1, n);
        }
    }
};

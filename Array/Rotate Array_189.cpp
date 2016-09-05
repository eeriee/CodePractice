class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k > 0){
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> tmp = nums;
        for(int i = n-k, j = 0; j < k; ++j){
            nums[j] = tmp[i];
            ++i;
        }
        for(int i = 0, j = k; i < n-k; ++i){
            nums[j] = tmp[i];
            ++j;
        }
    }
};

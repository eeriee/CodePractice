class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        
        int count = 0, lmt = target > 0 ? target : 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2 && nums[i] < lmt; ++i){
            int ret = target - nums[i];
            for(int j = i+1, k = n-1; k > j;){
                if(nums[j] + nums[k] >= ret) --k;
                else{
                    count += k - j;
                    ++j;
                }
            }
        }
        
        return count;
    }
};
//two pointers O(n^2)

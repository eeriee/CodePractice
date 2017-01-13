// re-do the problem Jan 12
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; ++i){
            int tar = target - nums[i];
            int j = i+1, k = n-1;
            while(j < k){
                if(nums[j] + nums[k] < tar){
                    count += k - j;
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return count;
    }
};
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

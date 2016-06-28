class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, count = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] == ele)
                ++count;
            else if(count != 0)
                --count;
            else
                ele = nums[i];
        }
        count = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == ele)
                ++count;
        }
        return ele;
    }
};

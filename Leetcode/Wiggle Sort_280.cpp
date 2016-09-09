/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i){
            if(( i%2 == 0 && nums[i] > nums[i-1])|| (i%2 == 1 && nums[i] < nums[i-1])){
                int tmp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = tmp;
            }
        }
    }
};
/*
slow solution: remember the sort method.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp = nums;
        for(int i = 0, j = 0, k = nums.size() - 1; i < nums.size(); ++i){
            if(i % 2){
                nums[i] = tmp[k];
                --k;
            }else{
                nums[i] = tmp[j];
                ++j;
            }
        }
    }
};
*/

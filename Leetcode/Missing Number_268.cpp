// bit manipu
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n;
        for(int i = 0; i < n; ++i){
            sum = sum^i^nums[i];
        }
        return sum;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n;
        for(int i = 0; i < n; ++i){
            sum += i - nums[i];
        }
        return sum;
    }
};
// my solu
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int num: nums){
            sum += num;
        }
        return n*(n+1)/2 - sum;
    }
};
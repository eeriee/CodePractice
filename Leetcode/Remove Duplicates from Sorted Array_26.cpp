// my O(n) solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, i = 0, pos = 0, n = nums.size();
        while(i < n){
            ++cnt;
            nums[pos++] = nums[i];
            while(i < n-1 && nums[i+1] == nums[i]) ++i;
            ++i;
        }
        return cnt;
    }
};
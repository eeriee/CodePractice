// O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = target - nums[i];
            for(int x = i+1, y = nums.size()-1; x < y; ){
                int sum = nums[x] + nums[y];
                if(sum == tmp) return target;
                if(abs(sum-tmp) < diff){
                    diff = abs(sum-tmp);
                    res = sum+nums[i];
                }
                if(sum > tmp){
                    --y;
                }else{
                    ++x;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        int first = 1, second, third, sum;
        
        for(int i = 0; i < n-2 && nums[i] <= 0; ++i){
             if(nums[i] == first) continue;
             first = nums[i];
             for(int j = i+1, k = n-1; j < k;){
                 second = nums[j];
                 third = nums[k];
                 sum = first + second + third;
                 if(sum == 0){
                     sol.push_back({first, second, third});
                     while(j < k && nums[++j] == second);
                     while(j < k && nums[--k] == third);
                 }else if(sum < 0){ 
                     while(j < k && nums[++j] == second);
                 }else{
                     while(j < k && nums[--k] == third);
                 } 
             }
        }
        return sol;
    }
};

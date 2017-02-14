class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), start = 0, idx = 0, curr = nums[0], pos = 0, cnt = 0;
        while(cnt < n){
            do{
                pos = (idx+k)%n;
                swap(curr, nums[pos]);
                idx = pos;
                ++cnt;
            }while(idx != start);
            ++start;
            idx = start;
            curr = nums[idx];
        }
    }
};
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

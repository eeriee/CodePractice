// O(n) fast way
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k <= 0) return {};
        int n = nums.size();
        vector<int> ltoRmax(n);
        vector<int> rtoLmax(n);
        for(int i = 0, j = n-1; i < n; ++i, --j){
            if(i%k == 0){
                ltoRmax[i] = nums[i];
            }else{
                ltoRmax[i] = max(ltoRmax[i-1], nums[i]);
            }
            if(j%k == k-1 || j == n-1){
                rtoLmax[j] = nums[j];
            }else{
                rtoLmax[j] = max(rtoLmax[j+1], nums[j]);
            }
        }
        vector<int> res;
        for(int i = 0; i <= n-k; ++i){
            res.push_back(max(rtoLmax[i], ltoRmax[i+k-1]));
        }
        return res;
    }
};
// O(n)
// https://abitofcs.blogspot.com/2014/11/data-structure-sliding-window-minimum.html
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // use it to store the index
        vector<int> maxRes;
        for(int i = 0; i< nums.size(); ++i){
            // pop the [i-k]
           if(!dq.empty() && dq.front() == i-k) dq.pop_front(); 
           // pop the previous smaller ones in [i-k+1,i], because they won't be the max
           while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
           
           dq.push_back(i);
           if(i >= k-1) maxRes.push_back(nums[dq.front()]);
        }
        return maxRes;
    }
};
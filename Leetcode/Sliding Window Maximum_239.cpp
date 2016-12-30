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
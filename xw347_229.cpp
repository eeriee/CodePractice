class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lmt = n/3;
        int ele1, ele2, count1, count2;
        ele1 = count1 = count2 = 0;
        ele2 = 1;
        for(int i = 0; i < n; ++i){
            if(nums[i] == ele1) ++count1;
            else if(nums[i] == ele2) ++count2;
            else if(count1 == 0){
                ele1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                ele2 = nums[i];
                count2 = 1;
            }else{
                --count1;
                --count2;
            }
        }
        count1 = count2 = 0;
        for(int i = 0; i< n; ++i){
            if(nums[i] == ele1){
                ++count1;
            }else if(nums[i] == ele2){
                ++count2;
            }
        }
        vector<int> majorityEle;
        if(count1 > lmt) majorityEle.push_back(ele1);
        if(count2 > lmt) majorityEle.push_back(ele2);
        return majorityEle;
    }
};
//Boyer–Moore majority vote algorithm

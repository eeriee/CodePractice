class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int left = 0, right = n-1, maxLeft = 0, maxRight = 0, water = 0;
        while(left < right){
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            if(maxLeft <= maxRight){
                water += maxLeft- height[left];
                ++left;
            }else{
                water += maxRight - height[right];
                --right;
            }
        }
        return water;
    }
};
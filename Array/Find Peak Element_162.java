public class Solution {
    public int findPeakElement(int[] nums) {
        int len = nums.length;
        int l = 0, r = len - 1, m;
        m = (r + l) / 2;
        while(r > l){
            if(nums[m] < nums[m+1]) l = m+1;
            else r = m;
            m = (r + l) / 2;
        }
        return m;
    }
}

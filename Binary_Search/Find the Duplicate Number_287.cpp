// O(n) solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        //slow and fast start at O, and meet at B
        //slow travels X and fast travels 2X
        //because they meet at B, B should be in the circle.
        //assume circle length = c, so 2X - X = kc so that they can meet
        while(slow != fast){ 
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int finder = 0;
        //the duplicate value causes the start of the circle, assume at A.
        //because OB >= OA and AB is in the circle
        //if one starts from O and the other starts from B, they will first meet at A
        while(finder != slow){
            slow = nums[slow];
            finder = nums[finder];
        }
        return finder;
    }
};
//binary search, O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 1, high = n;
        while(low < high){
           int mid = low + (high-low)/2;
           int count = 0;
           for(int i = 0; i <= n; ++i){
               if(nums[i] <= mid) ++count;
           }
           if(count > mid){
               high = mid;
           }else{
               low = mid+1;
           }
        }
        return high;
    }
};
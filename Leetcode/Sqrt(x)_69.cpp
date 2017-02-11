class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int left = 1, right = x;
        while(left + 1< right){
            int mid = left + (right-left)/2;
            if(mid > x/mid){
                right = mid;
            }else{
                left = mid;
            }
        }
        return left;
    }
};
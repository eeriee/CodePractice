//O(logn)
class Solution {
public:
    double helper(double x, int n){
        if(n == 0) return 1;
        return n%2 == 0? helper(x*x,n/2) :x*helper(x*x,n/2);
    }
    double myPow(double x, int n) {
        double res;
        if(n < 0){
            res = 1/x*helper(1/x,-(n+1)); //avoid overflow
        }else{
            res = helper(x,n);
        }
        return res;
    }
};
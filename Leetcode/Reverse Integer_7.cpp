// my solu
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -1*x;
        } 
        int rem = x%10, res = rem;
        while(x/10 != 0){
            x = x/10;
            rem = x%10; 
            if(sign == 1 && (INT_MAX - rem)/10 < res){
                return 0;
            }else if((INT_MIN + rem)/10 > -res){
                return 0;
            }
            res = res*10 + rem;
        }
        return res*sign;
    }
};
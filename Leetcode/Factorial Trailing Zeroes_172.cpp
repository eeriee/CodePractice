//每个5的倍数提供一个5， 每个25的倍数提供额外一个5, so on and so forth
//提供5的比提供2的少，所以只需要考虑5
//O(logn)
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int cnt = 0;
        while(n >= 5){
            n = n/5;
            cnt += n;
        }
    }
};
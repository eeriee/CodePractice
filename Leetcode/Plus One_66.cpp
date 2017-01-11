//change in place
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1; i >=0; --i){
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                ++digits[i];
                return digits;
            }
        }
        if(!digits[0]){
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        return plusOneHelper(digits, digits.size()-1);
    }
    
    vector<int> plusOneHelper(vector<int> &digits, int i){
        if(i == -1){
            auto it = digits.begin();
            digits.insert(it, 1);
            return digits;
        }
        if(digits[i] < 9){
            digits[i] += 1;
            return digits;
        }else{
            digits[i] = 0;
            return plusOneHelper(digits, i-1);
        }
    }
};

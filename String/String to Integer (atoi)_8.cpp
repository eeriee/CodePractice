// too many corner cases
/*
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        int num = 0, sign = 1, i = 0;
        while(str[i] == ' ') ++i;
        if(!isdigit(str[i])){
            switch(str[i]){
                case '-':
                    sign *= -1;
                case '+':
                    ++i;
                    break;
                default:
                    return 0;
            }
        }
        for(; i < str.size(); ++i){
            if(isdigit(str[i])){
                int val = sign*(str[i] - '0');
                if(sign == -1 && (INT_MIN - val)/10 > num) return INT_MIN;
                else if(sign == 1 && (INT_MAX - val)/10 < num) return INT_MAX;
                num = num*10 + val;
            }else{
                break;
            }
        }
        return num;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size() - k; // final length
        if(!len) return "0";
        vector<char> stk(num.size());
        int top = -1; //like a stack
        for(char c: num){
            while(top >= 0 && stk[top] > c && k > 0){
                --top;
                --k;
            }
            stk[++top] = c;
        }
        int pos = 0;
        while(pos < len && stk[pos] == '0') ++pos;
        if(pos == len) return "0";
        string res;
        for(int i = pos; i < len; ++i){
            res += stk[i];
        }
        return res;
    }
};
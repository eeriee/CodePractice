class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string str = "";
        for(char c: S){
            if(c == '-') continue;
            if(c >= 'a' && c <= 'z') c += 'A' - 'a';
            str += c;
        }
        int len = str.size();
        int first = len%K;
        if(first == 0) first = K;
        string res = str.substr(0, first);
        for(int i = first; i < len; i+=K){
            res += '-';
            res += str.substr(i, K);
        }
        return res;
    }
};
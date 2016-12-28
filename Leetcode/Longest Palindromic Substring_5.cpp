// fast because skip duplicate
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;
        int maxLen = 0, pos = 0;
        for(int i = 0; i < len;){
            if(len-i<= maxLen/2) break;
            int j = i;
            while(i < len-1 && s[i] == s[i+1]) ++i; //skip duplicate
            int k = i++;
            while(j > 0 && k < len-1 && s[j-1] == s[k+1]){
                ++k;
                --j;
            }
            int newLen = k-j+1;
            if(newLen > maxLen){
                pos = j;
                maxLen = newLen;
            }
        }
        return s.substr(pos, maxLen);
    }
};

// lower but easy-read
class Solution {
public:
    int maxLen;
    int pos;
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;
        maxLen = 0;
        for(int i = 0; i < len; ++i){
            if(len-i<= maxLen/2) break;
            findPalindrome(s, i, i); //odd
            findPalindrome(s, i, i+1); //even;
        }
        return s.substr(pos, maxLen);
    }
    void findPalindrome(string& s, int i, int j){
        while(i >=0 && j < s.size() && s[i] == s[j]){
            --i;
            ++j;
        }
        if(j-i-1 > maxLen){
            maxLen = j-i-1;
            pos = i+1;
        }
    }
};
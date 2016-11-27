class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        return helper(n);
    }
    string helper(int n){
        if(n == 1) return "1";
        string s = helper(n-1);
        string ans;
        int len = s.size();
        for(int i = 0; i < len; ++i){
            int cnt = 1;
            while(i+1 < len && s[i] == s[i+1]){
                ++cnt;
                ++i;
            }
            ans += to_string(cnt) + s[i];
        }
        return ans;
    }
};
/*
class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        if(n == 1) return "1";
        return helper(n);
    }
    string helper(int n){
        if(n == 2) return "11";
        string s = helper(n-1);
        string ans;
        int cnt = 0;
        int len = s.size();
        for(int i = 0; i < len-1; ++i){
            ++cnt;
            if(s[i] != s[i+1]){
                ans += to_string(cnt) + s[i];
                cnt = 0;
            }
        }
        if(s[len-1] == s[len-2]){
            ans += to_string(++cnt);
            ans += s[len-1];
        }else{
            ans += "1";
            ans += s[len-1];
        }
        return ans;
    }
};
*/
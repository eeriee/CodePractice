//write by me - update Jan 10
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int count = 0, maxLen = 0, curLen = 0;
        vector<int> mp(257);
        for(int i = 0; i < s.size(); ++i){
            if(!mp[s[i]]) ++count;
            ++mp[s[i]];
            ++curLen;
            while(count > k){
                int start = i-curLen+1;
                --mp[s[start]];
                --curLen;
                if(!mp[s[start]]) --count;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
//Better Solution. Easily extend from substring2distinct. Vector<int> stores the frequency of char.
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(n == 0 || k == 0) return 0;
        
        vector<int> dict(128, 0);
        int i, len = 0, curr = 0, count = 0;
        for(i = 0; i < n; ++i){
            char c = s[i];
            ++dict[c];
            if(dict[c] == 1){
                ++count;
                while(count > k){
                    --dict[s[curr]];
                    if(dict[s[curr]] == 0) --count;
                    ++curr;
                }
            }
            len = max(len, i-curr+1);
        }
        
        return len;
    }
};
//My solution. Use vector<int> to store the postion of each char. slow. 44 ms.
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(n == 0 || k == 0) return 0;
        
        vector<int> dict(128, -1);
        set<char> prev;
        int i, len = 0, curr = 0, count = 0;
        for(i = 0; i < s.length(); ++i){
            char c = s[i];
            
            if(dict[c] < curr){
                ++count; 
                if(count > k){
                    len = max(len, i - curr);
                    count = k;
                    curr = i;
                    for(auto p: prev){
                        curr = min(dict[p], curr);
                    }
                    prev.erase(s[curr]);
                    ++curr;
                }
            } 
            prev.insert(c);
            dict[c] = i;
        }
        len = max(len, i - curr);
        return len;
    }
};
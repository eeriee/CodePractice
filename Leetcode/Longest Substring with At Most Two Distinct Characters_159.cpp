//My solution. Store the postion of each char. Not extendable to K distinct. 4ms
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> dict(128, -1);
        int i, len = 0, curr = 0, count = 0;
        for(i = 0; i < s.length(); ++i){
            char c = s[i];
            if(dict[c] < curr){
                ++count; 
                dict[c] = i;
                if(count > 2){
                    len = max(len, i - curr);
                    count = 2;
                    curr = dict[s[i-1]];
                }
            } 
            if(c != s[i-1]) dict[c] = i;
        }
        len = max(len, i - curr);
        return len;
    }
};
//Extendable solution. 4ms
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> dict(128, 0);
        int len = 0, curr = 0, count = 0;
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            ++dict[c];
            if(dict[c] == 1){
                ++count;
                while(count > 2){
                    --dict[s[curr]];
                    if(!dict[s[curr]]) --count;
                    ++curr;
                }
            }
            len = max(len, i - curr + 1);
        }
        return len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int len = 0, curr = 0, i;
        for(i = 0; i < s.length(); ++i){
            char c = s[i];
            if(mp.count(c) && mp[c] >= curr){
                len = max(len, i - curr);
                curr = mp[c]+ 1;
            }
            mp[c] = i;
        }
        len = max(len, i - curr);
        return len;
    }
};
/*
for ASCII char sequence, use this as a hashmap. Much faster.
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = 0, i;
        for (i = 0; i < s.length(); i++) {
            char c = s[i];
            if (dict[c] >= start){
                maxLen = max(maxLen, i - start);
                start = dict[c] + 1;
            }
            dict[c] = i;
        }
        maxLen = max(maxLen, i - start);
        return maxLen;
    }
};
*/
/*
Question:
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

*/

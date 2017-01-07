//dp[i] is set to true if a valid word (word sequence) ends at i-1. 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        unordered_set<string> dict;
        int maxLen = 0;
        for(string s: wordDict){
            dict.insert(s);
            if(s.size() > maxLen) maxLen = s.size(); //use maxLen to shorten time
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); ++i){
            for(int j = i-1; j >= max(i-maxLen, 0); --j){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    if(dict.find(word) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
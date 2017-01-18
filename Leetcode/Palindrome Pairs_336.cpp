class Solution {
public:
    bool isPalindrome(string& s){
        for(int i = 0, j = s.size()-1; i < j; ++i, --j){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if(words.empty()) return {};
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); ++i){
            mp[words[i]] = i;
        }
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); ++i){
            string word = words[i];
            for(int j = 0; j <= word.size(); ++j){ //<= is to consider "" in words
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);
                if(isPalindrome(prefix)){
                    string ans(suffix.rbegin(), suffix.rend());
                    if(mp.find(ans) != mp.end() && mp[ans] != i)
                        res.push_back({mp[ans], i});
                }
                if(isPalindrome(suffix)){
                    string ans(prefix.rbegin(), prefix.rend());
                    if(mp.find(ans) != mp.end() && mp[ans] != i && !suffix.empty()) // to avoid repeating results 
                        res.push_back({i, mp[ans]});
                }
            }
        }
        return res;
    }
};
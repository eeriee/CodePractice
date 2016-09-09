class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string val = s;
            sort(s.begin(), s.end());
            mp[s].push_back(val);
        }
        
        vector<vector<string>> groups;
        for(auto it: mp)
            groups.push_back(it.second);
        return groups;
    }
};

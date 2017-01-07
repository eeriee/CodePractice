//use array to store
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};

//use hashmap, slower
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            ++mp[s[i]];
            --mp[t[i]];
        }
        for(auto item: mp){
            if(item.second) return false;
        }
        return true;
    }
};
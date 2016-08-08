// Stupid Solution. Compare strings a lot.
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<int, vector<string>> mp;
        unordered_map<string, vector<string>> groups;
        for(int i = 0; i < strings.size(); ++i){
            string s1 = strings[i];
            int len = s1.length();
            if(mp.count(len)){
                bool same = false;
                for(int j = 0; j < mp[len].size(); ++j){
                    string s2 = mp[len][j];
                    if(s2[0] > s1[0]) same = isSameSequence(s1,s2,len);
                    else same = isSameSequence(s2,s1,len);
                    if(same){
                        groups[s2].push_back(s1);
                        break;
                    }
                }
                if(!same){
                    mp[len].push_back(s1);
                    groups[s1].push_back(s1);
                }
            }else{
                mp[len].push_back(s1);
                groups[s1].push_back(s1);
            }
        }
        vector<vector<string>> ans(groups.size());
        int i = 0;
        for(auto it = groups.begin(); it != groups.end(); ++it, ++i){
            ans[i] = it->second;
        }
        return ans;
    }
    bool isSameSequence(string s1, string s2, int len){
        int dist = s2[0] - s1[0];
        for(int i = 1; i < len; ++i){
            int d = s2[i] - s1[i];
            if(d < 0){
                d += 26;
            }
            if(d != dist) return false;
        }
        return true;
    }
};
//Encode each string as a key. strings that belong to the same shifting sequence has the same key.
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for(string s: strings)
            mp[getKey(s)].push_back(s);
        vector<vector<string>> groups;
        for(auto it: mp)
            groups.push_back(it.second);
        return groups;
    }
    string getKey(string s){
        int len = s.length();
        string key = "";
        if(len){
        //1. compute the difference between each letter in the word with the first letter.
            char base = s[0]; 
            for(int i = 0; i < len; ++i){ //start from zero to ensure the length. otherwize len = 1 string will has same key as null string.
                int d = s[i] - base;
                if(d < 0) d +=26;
                key += 'a' + d;
            }
        /*2. encode key as "s[1] - s[0], s[2] - s[1], ..., s[n - 1] - s[n -2],"
                int d = s[i] - s[i-1]; however it only works for all non-null string.
        */
        }
        return key;
    }
};
/*
Question:
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    vector<string> mp = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> ans;
        combine(ans, digits, "", 0);
        return ans;
    }
    void combine(vector<string>&ans, string s, string prev, int i){
        if(i == s.size()){
            ans.push_back(prev);
            return;
        }
    
        for(char c: mp[s[i]-'0']){
            combine(ans, s, prev+c, i+1);
        }
    }
};

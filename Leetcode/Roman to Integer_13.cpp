class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp ={
            {'I',1}, {'V',5},{'X',10}, {'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int n = s.size();
        int num = mp[s[n-1]];
        for(int i = n-2; i >= 0; --i){
            int val = mp[s[i]];
            num += val < mp[s[i+1]]? -val:val;
        }
        return num;
    }
};
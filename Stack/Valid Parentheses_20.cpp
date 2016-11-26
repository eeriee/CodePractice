class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {{'(', ')'}, {'{','}'}, {'[',']'}};
        for(char c: s){
            if(mp.count(c)){
               stk.push(c); 
            }else{
               if(stk.empty() || mp[stk.top()] != c)
                   return false;
               stk.pop();
            }
        }
        return stk.empty();
    }
};
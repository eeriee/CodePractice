class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(char c: s){
            if(c == ']'){
                string str;
                for(;;){
                    char ch = stk.top();
                    stk.pop();
                    if(ch == '[') break;
                    str += ch;
                }
                reverse(str.begin(), str.end());
                string num;
                while(!stk.empty()){
                    char ch = stk.top();
                    if(!isdigit(ch)) break;
                    stk.pop();
                    num += ch;
                }
                reverse(num.begin(), num.end());
                int cnt = stoi(num);
                for(int i = 0; i < cnt; ++i){
                    for(char c: str){
                        stk.push(c);
                    }
                }
                
            }else{
                stk.push(c);
            }
        }
        string res;
        while(!stk.empty()){
            char c = stk.top();
            stk.pop();
            res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string decodeString(string s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if(abs(l1-l2) > 1) return false;
        bool flag = false;
        if(l1 == l2){
            for(int i = 0; i < l1; ++i){
                if(s[i] != t[i]){
                    if(!flag) flag = true;
                    else return false;
                }
            }
        }else{
            int len;
            string s1, s2;
            if(l1 > l2){
                len = l1;
                s1 = s;
                s2 = t;
            }else{
                len = l2;
                s1 = t;
                s2 = s;
            }
            for(int i = 0, j = 0; i < len; ++i){
                if(s1[i] != s2[j]){
                    if(!flag){ 
                        flag = true;
                    }else return false;
                }else{
                    ++j;
                }
            }
        }
        return flag;
    }
};

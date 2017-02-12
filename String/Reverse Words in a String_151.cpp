class Solution {
public:
    void reverseWord(string &s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    void reverseWords(string &s) {
        int n = s.size(), i = 0, j = 0;
        //reverseWord(s, 0, n-1);
        reverse(s.begin(), s.end());
        int start = 0, pos = 0, end = 0;
        for(i = 0; i < n; ++i){
            if(s[i] != ' '){
                if(pos != 0) s[pos++] = ' ';
                j = i;
                while(j < n && s[j] != ' '){
                    s[pos++] = s[j++];
                }
                int len = j-i;
                //reverseWord(s, pos-len, pos-1);
                reverse(s.begin()+pos-len, s.begin()+pos);
                i = j;
            }
        }
        s.erase(s.begin()+pos, s.end());
    }
};
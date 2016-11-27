class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int pos = 0, hlen = haystack.size(), nlen = needle.size();
        for(int i = 0; i < hlen-nlen+1; ++i){
            int j = 0;
            for(; j < nlen; ++j){
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == nlen) return i;
        }
        return -1;
    }
};
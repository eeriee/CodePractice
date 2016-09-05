//in-place without allocating extra space
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        int len = s.length();
        int i = 0, j;
        while(i < len){
            j = i;
            while(j < len && s[j] != ' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
            i = j+1;
        }
    }
};

//expand space
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        int i = len-1, j = 0, step = 0;
        while(step < len){
            if(s[i] == ' '){
                s.insert(j, s.substr(i+1,len-1-i) + " ");
                s.resize(len);
                j += len-i;
                i = len;
            }
            ++step;
            --i;
        }
    }
};

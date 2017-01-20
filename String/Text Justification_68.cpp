//my solution
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0; i < words.size(); ){
            string str = words[i];
            int len = words[i].size(), j;
            for(j = i+1; j < words.size(); ++j){
                if(len + 1 + words[j].size() > maxWidth) break;
                len += 1 + words[j].size();
            }
            int num = j-i-1;
            if(!num || j == words.size()){
                for(int k = i+1; k < j; ++k){
                    str += ' ' + words[k];
                }
                str += string(maxWidth - str.size(), ' ');
            }else{
                len -= num;
                int red = (maxWidth - len)%num;
                int space = (maxWidth - len - red)/num;
                for(int k = i+1; k < j; ++k){
                    if(red > 0){
                        str += string(space+1, ' ') + words[k];
                        --red;
                    }else{
                        str += string(space, ' ') + words[k];
                    }
                }
            }
            res.push_back(str);
            i = j;
        }
        return res;
    }
};
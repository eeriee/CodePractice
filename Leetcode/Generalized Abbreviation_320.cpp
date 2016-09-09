//think too long
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int len = word.size();
        if(len == 0) return {""};
        vector<string> abbrs;
        abbrs.push_back(word);
        helper(word, "", abbrs, len);
        return abbrs;
    }
    
    void helper(string w, string head, vector<string> & v, int len){
        for(int i = 0; i < len; ++i){
            if(i){
                string num = to_string(i);
                string s = num + w.substr(i);
                v.push_back(head + s);
                int start = num.size()+1;
                if(s.size() > num.size()+1){
                    helper(s.substr(start), head + s.substr(0, start), v, s.size()-start);
                }
            }else{
                if(len > 1)
                    helper(w.substr(1), head + w.substr(0, 1), v, w.size()-1);
            }
        }
        v.push_back(head + to_string(len));
    }
    
};

//clear solution

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int len = word.size();
        vector<string> abbrs;
        helper(word, "", abbrs, 0, 0);
        return abbrs;
    }
    
    void helper(string w, string head, vector<string> & v, int pos, int count){
        if(pos == w.size()){
            if(count) head += to_string(count);
            v.push_back(head);
        }else{
            helper(w, head, v, pos+1, count+1); //abbrev the w[pos]
            string tail = count > 0 ? to_string(count):"";
            helper(w, head + tail + w.substr(pos, 1), v, pos+1, 0); //keep the w[pos]
        }
    }
    
};
/*Google
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

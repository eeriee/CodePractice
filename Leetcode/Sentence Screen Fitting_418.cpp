class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str = "";
        for(string s: sentence) str += s + ' ';
        int len = str.size();
        int count = 0;
        for(int i = 0; i < rows; ++i, ++count){
            count += cols;
            while(count > -1 && str[count%len] != ' ') --count;
        }
        return count/len;
    }
};
//O(m + n), m: length of sentence by char, n: rows
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str = "";
        for(string s: sentence) str += s + ' ';
        int len = str.size();
        vector<int> dp(len, 0);
        for(int i = 1; i < len; ++i){
            dp[i] = str[i] == ' '? 1: dp[i-1]-1;
        }
        int count = 0;
        for(int i = 0; i < rows; ++i){
            count += cols;
            count += dp[count%len];
        }
        return count/len;
    }
};
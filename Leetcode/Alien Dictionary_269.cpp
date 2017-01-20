//my solution
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        if(words.size() == 1) return words[0];
        unordered_map<char, unordered_set<char>> mp;
        unordered_set<char> allChar;
        for(int i = 0; i < words.size()-1; ++i){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            int j;
            for(j = 0; j < len; ++j){
                allChar.insert(s1[j]);
                if(s1[j] == s2[j]) continue;
                mp[s1[j]].insert(s2[j]);
                allChar.insert(s2[j]);
                break;
            }
            if(j == len && s1.size() > s2.size()) return "";
            for(int k = j; k < s1.size(); ++k) allChar.insert(s1[k]);
            for(int k = j; k < s2.size(); ++k) allChar.insert(s2[k]);
        }
        unordered_map<char, int> pre;
        for(auto item: mp){
            for(char c: item.second){
                ++pre[c];
            }
        }
        queue<char> noPre;
        for(char c: allChar){
            if(!pre[c]) noPre.push(c);
        }
        string res = "";
        for(int i = 0; i < allChar.size(); ++i){
            if(noPre.empty()) return "";
            char c = noPre.front();
            res += c;
            noPre.pop();
            for(char next: mp[c]){
                if(!--pre[next]) noPre.push(next);
            }
        }
        return res;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> beginSet({beginWord}), endSet({endWord});
        int transLen = 2;
        while(!beginSet.empty() && !endSet.empty()){
            if(beginSet.size() > endSet.size()){
                swap(beginSet, endSet);
            }
            unordered_set<string> midSet;
            for(string s: beginSet){
                for(int i = 0; i < s.size(); ++i){
                    char letter = s[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        s[i] = c;
                        if(endSet.count(s)) return transLen;
                        if(wordList.count(s)){
                            midSet.insert(s);
                            wordList.erase(s);
                        }
                    }
                    s[i] = letter;
                }
            }
            swap(beginSet, midSet);
            ++transLen;
        }
        return 0;
    }
};
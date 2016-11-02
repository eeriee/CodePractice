class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(bankSet.count(end) == 0) return -1;
        unordered_set<string> startSet({start}), endSet({end});
        int mut = 1; 
        while(!startSet.empty() && !endSet.empty()){
            if(startSet.size() > endSet.size())
                swap(startSet, endSet);
            unordered_set<string> midSet;
            for(string s: startSet){
                for(int i = 0; i < s.size(); ++i){
                    char letter = s[i];
                    for(char c: "ACGT"){
                        s[i] = c;
                        if(endSet.count(s))
                            return mut;
                        if(bankSet.count(s)){
                            midSet.insert(s);
                            bankSet.erase(s);
                        }
                    }
                    s[i] = letter;
                }
            }
            swap(midSet, startSet);
            ++mut;
        }
        return -1;
    }
};
class Solution {
public:
    void split(vector<string>& strs, string& input){
        stringstream ss(input);
        string str;
        while(getline(ss, str)){ // split each line 
            strs.push_back(str);
        }
    }
    int lengthLongestPath(string input) {
        vector<string> strs;
        split(strs, input);
        vector<int> level(strs.size());
        int maxLen = 0;
        for(string str: strs){
            int lv = str.find_last_of('\t')+1; //find the last \t. if no \t, pos = 0
            // lv present the current level, also present the number of \t
            level[lv+1] = level[lv] + str.size() + 1 - lv;  // + '\' - no. of \t
            if(str.find('.') != -1) maxLen = max(level[lv+1]-1, maxLen); // - '\'
        }
        return maxLen;
    }
};
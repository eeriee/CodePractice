class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int dist = INT_MAX, w1 = -1, w2 = -1;
        bool same = (word1 == word2); //use it to avoid repeated comparison.
        for(int i = 0; i < words.size(); ++i){
            if(word1 == words[i]){
                if(same) w2 = w1;
                w1 = i;
            } 
            else if(word2 == words[i]) w2 = i;
            if(w1 != -1 && w2 != -1) dist = min(abs(w1-w2), dist);
        }
        return dist;
    }
};

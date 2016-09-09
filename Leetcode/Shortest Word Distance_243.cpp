class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dist = INT_MAX, w1 = -1, w2 = -1;
        for(int i = 0; i < words.size(); ++i){
            if(word1 == words[i]) w1 = i;
            else if(word2 == words[i]) w2 = i;
            if(w1 != -1 && w2 != -1) dist = min(abs(w1-w2), dist);
        }
        return dist;
    }
};

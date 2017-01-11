class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.size() == 0) return {};
        int n = words[0].size();
        vector<vector<string>> squares;
        vector<string> square(n);
        unordered_map<string, vector<string>> prefixMp;
        for(string word: words){
            for(int i = 0; i < word.size(); ++i){
                prefixMp[word.substr(0, i)].push_back(word); 
            }
        }
        findSquares(0, n, prefixMp, square, squares);
        return squares;
    }
    void findSquares(int curr, int n, unordered_map<string, vector<string>>& prefixMp, vector<string>& square, vector<vector<string>>& squares){
        if(curr == n){
            squares.push_back(square);
            return;
        }
        string prefix = "";
        for(int i = 0; i < curr; ++i){
            prefix += square[i][curr];
        }
        for(string word: prefixMp[prefix]){
            square[curr] = word;
            findSquares(curr+1, n, prefixMp, square, squares);
        }
    }
};
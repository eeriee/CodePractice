class Solution {
private:
    vector<int> delta = {0,1,0,-1,0};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(findword(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    bool findword(vector<vector<char>>& board, int x, int y, string& word, int idx){
        if(idx == word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[idx]) return false;
        char c = board[x][y];
        board[x][y] = '#';
        for(int i = 0; i < 4; ++i){
            int newX = x + delta[i], newY = y + delta[i+1];
            if(findword(board, newX, newY, word, idx+1)) return true;
        }
        board[x][y] = c;
        return false;
    }
};
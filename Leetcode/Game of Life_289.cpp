//To solve it in place, we use 2 bits to store 2 states:

// [2nd bit, 1st bit] = [next state, current state]

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int lives = 0;
                for(int k = max(i-1,0); k < min(m,i+2); ++k){
                    for(int h = max(j-1,0); h < min(n,j+2); ++h){
                        if(k == i && h == j) continue;
                        lives += board[k][h]&1;
                    }
                }
                if(board[i][j]){
                    if(lives == 2 || lives == 3) board[i][j] = 3;
                    else board[i][j] = 1;
                }else{
                    if(lives == 3) board[i][j] = 2;
                    else board[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};
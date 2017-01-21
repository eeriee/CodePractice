class TrieNode{
public:
    TrieNode* children[26];
    int idx;
    TrieNode(){
        memset(children, 0, sizeof(children));
        idx = -1;
    }
};

class Solution {
public:
    void insert(TrieNode* root, string key, int idx){
        TrieNode* p = root;
        for(char c: key){
            int x = c - 'a';
            if(p->children[x] == NULL)
                p->children[x] = new TrieNode();
            p = p->children[x];
        }
        p->idx = idx;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty() || words.empty()) return {};
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); ++i){
            insert(root, words[i],i);
        }
        vector<string> res;
        vector<int> delta = {0,1,0,-1,0};
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                backtrack(board, root, words, res, i, j, delta);
            }
        }
        return res;
    }
    void backtrack(vector<vector<char>>& board, TrieNode* root, vector<string>& words, vector<string>& res, int x, int y, vector<int>& delta){
        char c = board[x][y];
        if(c == '#' || root->children[c-'a'] == NULL) return;
        TrieNode* p = root->children[c-'a'];
        if(p->idx != -1){
            res.push_back(words[p->idx]);
            p->idx = -1;
        }
        board[x][y] = '#';
        for(int i = 0; i < 4; ++i){
            int X = x + delta[i];
            int Y = y + delta[i+1];
            if(X >= 0 && X < board.size() && Y >= 0 && Y < board[0].size()){
                backtrack(board, p, words, res, X, Y, delta);
            }
        }
        board[x][y] = c;
    }
};
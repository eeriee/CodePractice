class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* children[26];
    bool isLeaf;
    TrieNode() {
        memset(children,0,sizeof(children));
        isLeaf = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.length();
        TrieNode* tmpR = root;
        for(int i = 0; i < len; ++i){
            int x = word[i] - 'a';
            if(tmpR->children[x] == NULL){
                tmpR->children[x] = new TrieNode();
            }
            tmpR = tmpR->children[x];
        }
        tmpR->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int len = word.length();
        TrieNode* tmpR = root;
        for(int i = 0; i < len; ++i){
            int x = word[i] - 'a';
            if(tmpR->children[x] == NULL)
                return false;
            tmpR = tmpR->children[x]; 
        }
        return tmpR->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* tmpR = root;
        for(int i = 0; i < len; ++i){
            int x = prefix[i] -'a';
            if(tmpR->children[x] == NULL)
                return false;
            tmpR = tmpR->children[x];
        }
        return true;
    }

private:
    TrieNode* root;
};

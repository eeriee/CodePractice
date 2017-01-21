class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode()
    {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};

// one format
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
        TrieNode* p = root;
        for(int i = 0; i < word.length(); ++i){
            int x = word[i] - 'a';
            if(p->children[x] == NULL){
                p->children[x] = new TrieNode();
            }
            p = p->children[x];
        }
        p->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); ++i){
            int x = word[i] - 'a';
            if(p->children[x] == NULL)
                return false;
            p = p->children[x]; 
        }
        return p->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* p = root;
        for(int i = 0; i < len; ++i){
            int x = prefix[i] -'a';
            if(p->children[x] == NULL)
                return false;
            p = p->children[x];
        }
        return true;
    }

private:
    TrieNode* root;
};

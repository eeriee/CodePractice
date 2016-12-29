struct Node{
    int val;
    int key;
    Node* prev;
    Node* nxt;
    Node() = default;
    Node(int key, int value):key(key), val(value), prev(nullptr), nxt(nullptr){}
};
class LRUCache{
public:
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    void remove(Node* n){
        n->nxt->prev = n->prev;
        n->prev->nxt = n->nxt;
        n->prev = nullptr;
        n->nxt = nullptr;
    }
    void insert(Node* n){
        n->nxt = head->nxt;
        head->nxt->prev = n;
        n->prev = head;
        head->nxt = n;
    }
    int get(int key) {
        if(mp.count(key)){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        Node* n = new Node(key, value);
        if(mp.count(key)){
            remove(mp[key]);
        }else if(mp.size() == cap){
            int k = tail->prev->key;
            remove(tail->prev);
            mp.erase(k);
        }
        mp[key] = n;
        insert(n);
    }
};
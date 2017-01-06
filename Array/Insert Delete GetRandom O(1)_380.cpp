//follow up add duplicated number, then use unordered_map<int, unordered_set<int>> mp;
class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> ve;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val] = ve.size();
        ve.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int index = mp[val];
        int n = ve.size();
        int last = ve[n-1];
        if(index != n-1){
            mp[last] = index;
            ve[index] = last;
        }
        ve.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = ve.size();
        int index = rand()%n;
        return ve[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
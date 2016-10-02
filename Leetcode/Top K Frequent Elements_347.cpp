//way to write comparison for pq
class cmp{
public:
    bool operator() (const pair<int,int>& x, const pair<int,int>& y){
        return x.second > y.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i: nums){
            ++freq[i];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto f: freq){
            pq.push(f);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            auto p = pq.top();
            res.push_back(p.first);
            pq.pop();
        }
        return res;
    }
};
//no self-defined comparison
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i: nums){
            ++freq[i];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto f: freq){
            pq.push(make_pair(f.second, f.first)); //change the order, frequency first
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            auto p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }
        return res;
    }
};

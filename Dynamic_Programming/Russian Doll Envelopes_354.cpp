//pay attention to the cmp function. O(nlogn)
class Solution {
    static bool cmp(const pair<int,int> &e1, const pair<int,int> &e2){
        if(e1.first == e2.first) return e1.second > e2.second;
        return e1.first < e2.first;
    }
    public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> v;
        for(auto en: envelopes){
            int h = en.second;
            auto pos = lower_bound(v.begin(), v.end(), h);
            if(pos == v.end())
                v.push_back(h);
            else
                *pos = h;
        }
        return v.size();
    }
};
//O(n^2)
class Solution {
public:
struct Triplet
{
  int  first, second, third;
  Triplet(int a, int b, int c){
      first = a;
      second = b;
      third = c;
  }
};
struct cmp{
    bool operator () (const pair<int,int> &e1, const pair<int,int> &e2) const{
        if(e1.first > e2.first) return true;
        if(e1.first == e2.first) return e1.second > e2.second;
        return false;
    }
};
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        for(auto en: envelopes){
            q.push(en);
        }
        vector<Triplet> v;
        while(!q.empty()){
            auto en = q.top();
            q.pop();
            int maxEn = 1;
            for(int i = 0; i < v.size(); ++i){
                
                if(en.first > v[i].first && en.second > v[i].second){
                    maxEn = max(maxEn, v[i].third+1);
                }
            }
            v.push_back(Triplet(en.first, en.second, maxEn));
        }
        int count = 0;
        for(Triplet t: v){
            count = max(count, t.third);
        }
        return count;
    }
};

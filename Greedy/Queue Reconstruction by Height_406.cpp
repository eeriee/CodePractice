// using the anonymous function
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    });
    vector<pair<int,int>> sol;
    for (auto person : people){
        sol.insert(sol.begin() + person.second, person);
    }
    return sol;
}
// write a cmp class
class cmp{
public:
    bool operator()(const pair<int,int> p1, const pair<int,int> p2) const{
        if(p1.first == p2.first)
            return p1.second < p2.second; 
        return p1.first > p2.first;
    }
};
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if(people.empty()) return {};
        sort(people.begin(), people.end(), cmp());
        vector<pair<int, int>> res;
        for(auto pp: people){
            res.insert(res.begin()+pp.second,pp);
        }
        return res;
    }
};
// iterative
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> ngb;
        for(auto ticket: tickets){
            ngb[ticket.first].insert(ticket.second);
        }
        vector<string> res;
        stack<string> path;
        path.push("JFK");
        while(!path.empty()){
            string start = path.top();
            if(ngb[start].empty()){
                path.pop();
                res.push_back(start);
            }else{
                path.push(*ngb[start].begin());
                ngb[start].erase(ngb[start].begin());
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//recursive
class Solution {
public:
    void dfs(const string& start, unordered_map<string, multiset<string>>& ngb, vector<string>& path){
        while(!ngb[start].empty()){
            string end = *(ngb[start].begin());
            ngb[start].erase(ngb[start].begin());
            dfs(end, ngb, path);
        }
        path.push_back(start);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> ngb;
        for(auto ticket: tickets){
            ngb[ticket.first].insert(ticket.second);
        }
        vector<string> path;
        string start = "JFK";
        dfs(start, ngb, path);
        reverse(path.begin(), path.end());
        return path;
    }
};
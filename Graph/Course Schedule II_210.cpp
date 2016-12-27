// bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0) return {};
        
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].insert(pre.first);
        }
        vector<int> indegree(numCourses);
        for(auto ngb: graph){
            for(int node: ngb){
                ++indegree[node]; //mark incoming edges;
            }
        }
        queue<int> noPre;
        for(int i = 0; i < numCourses; ++i){
            if(!indegree[i])
                noPre.push(i);
        }
        vector<int> order;
        for(int i = 0; i < numCourses; ++i){
            if(noPre.empty()) return {}; // a cycle exists
            int v = noPre.front();
            noPre.pop();
            order.push_back(v);
            for(int u: graph[v]){
                if(!--indegree[u]){
                    noPre.push(u);
                }
            }
        }
        return order;
    }
};

//dfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0) return {};
        
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].insert(pre.first);
        }
        vector<bool> onPath(numCourses, false), visited(numCourses, false);
        stack<int> s;
        for(int i = 0; i < numCourses; ++i){
            if(!visited[i] && !dfs(i, onPath, visited, graph, s))
                return {};
        }
        vector<int> order;
        while(!s.empty()){
            order.push_back(s.top());
            s.pop();
        }
        return order;
    }
    bool dfs(int node, vector<bool>& onPath, vector<bool>& visited, vector<unordered_set<int>>& graph, stack<int>& s){
        if(onPath[node]) return false;
        onPath[node] = true;
        for(int ne: graph[node]){
            if(!visited[ne] && !dfs(ne, onPath, visited, graph, s)) // put all course depend on pre first
                return false;
        }
        visited[node] = true;
        onPath[node] = false;
        s.push(node);
        return true;
    }
};